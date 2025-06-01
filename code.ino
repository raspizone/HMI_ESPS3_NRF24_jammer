#include "pins_config.h"
#include "LovyanGFX_Driver.h"

#include <Arduino.h>
#include <lvgl.h>
#include <Wire.h>
#include <SPI.h>

#include <stdbool.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include "ui.h" 
/* Expand IO */
#include <TCA9534.h>
#include <PCA9557.h>
PCA9557 Out;
#include <SPI.h>
#include <Wire.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <driver/i2c.h>

#define CE_PIN 20
#define CSN_PIN 19

// instantiate an object for the nRF24L01 transceiver
RF24 radio(CE_PIN, CSN_PIN);

SPIClass* hspi = nullptr;

#define HSPI_MISO  4
#define HSPI_MOSI  6
#define HSPI_SCLK  5
#define HSPI_SS    19
char payload[32];


TCA9534 ioex;

LGFX gfx;

/* Change to your screen resolution */
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *buf;
static lv_color_t *buf1;

uint16_t touch_x, touch_y;


extern lv_obj_t *ui_SliderSelectChannel;
extern lv_obj_t *ui_allchannelcheckbox;
extern lv_obj_t *ui_channel; 
extern lv_obj_t *ui_TransmissionSpeedDropdown; 
extern lv_obj_t * ui_ScanBleResult;
extern lv_obj_t * ui_initbutton;
extern lv_obj_t * ui_logtextbox;


//  Display refresh
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  if (gfx.getStartCount() > 0) {
    gfx.endWrite();
  }
  gfx.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::rgb565_t *)&color_p->full);

  lv_disp_flush_ready(disp);  //	Tell lvgl that the refresh is complete
}

//  Read touch
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
  data->state = LV_INDEV_STATE_REL;// The state of data existence when releasing the finger
  bool touched = gfx.getTouch( &touch_x, &touch_y );
  if (touched)
  {
    data->state = LV_INDEV_STATE_PR;

    //  Set coordinates
    data->point.x = touch_x;
    data->point.y = touch_y;
  }
}



const byte address[6] = "00001";
void setup()
{
  Serial.begin(115200); 

  pinMode(19, OUTPUT);

  Wire.begin(15, 16);
  delay(50);

  ioex.attach(Wire);
  ioex.setDeviceAddress(0x18);
  ioex.config(1, TCA9534::Config::OUT);
  ioex.config(2, TCA9534::Config::OUT);
  ioex.config(3, TCA9534::Config::OUT);
  ioex.config(4, TCA9534::Config::OUT);

  /* Turn on backlight*/
  ioex.output(1, TCA9534::Level::H);

  // GT911 power on timing ->Select 0x5D
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
  ioex.output(2, TCA9534::Level::L);
  delay(20);
  ioex.output(2, TCA9534::Level::H);
  delay(100);
  pinMode(1, INPUT);
  /*end*/

  // Init Display
  gfx.init();
  gfx.initDMA();
  gfx.startWrite();
  gfx.fillScreen(TFT_BLACK);

  lv_init();
  size_t buffer_size = sizeof(lv_color_t) * LCD_H_RES * LCD_V_RES;
  buf = (lv_color_t *)heap_caps_malloc(buffer_size, MALLOC_CAP_SPIRAM);
  buf1 = (lv_color_t *)heap_caps_malloc(buffer_size, MALLOC_CAP_SPIRAM);

  lv_disp_draw_buf_init(&draw_buf, buf, buf1, LCD_H_RES * LCD_V_RES);

  // Initialize display
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  // Change the following lines to your display resolution
  disp_drv.hor_res = LCD_H_RES;
  disp_drv.ver_res = LCD_V_RES;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  // Initialize input device driver program
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  delay(100);

  gfx.fillScreen(TFT_BLACK);
  Serial.begin(115200);
  Serial.println(F("serial init"));
  Wire.begin(15, 16);
  delay(50);

  Out.reset();
  Out.setMode(IO_OUTPUT); // Config IO0 of PCA9557 to INPUT mode
  Out.setState(IO1, IO_HIGH);

 
  while (!Serial) {
    // some boards need to wait to ensure access to serial over USB
  }

  hspi = new SPIClass(HSPI); // by default VSPI is used
  // to use the custom defined pins, uncomment the following
  hspi->begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);

  if (!radio.begin(hspi)) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {}  // hold in infinite loop
  }
  else
  {
    Serial.println(F("radio hardware is OK!!"));
  }

  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);  //RF24_250KBPS  RF24_1MBPS  RF24_2MBPS
  radio.setChannel(50);
  radio.stopListening();
  
  for (int i = 0; i < 32; i++) {
    payload[i] = random(0, 256);
  }
  // lv_demo_widgets();// Main UI interface
  ui_init();

  Serial.println( "Setup done" );
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */

  static int last_channel = -1;
  static bool last_all_channels = false;
  int channel = 2;
  int current_channel = lv_slider_get_value(ui_SliderSelectChannel);
  bool all_channels = lv_obj_has_state(ui_allchannelcheckbox, LV_STATE_CHECKED);

  // Si el canal cambió o el checkbox cambió
  if (current_channel != last_channel || all_channels != last_all_channels) {
    char buffer[8];
    sprintf(buffer, "%d", current_channel);
    lv_label_set_text(ui_channel, buffer);
    Serial.print("Canal seleccionado: ");
    Serial.println(current_channel);

    if (all_channels) {
      Serial.println("Modo: TODOS LOS CANALES ACTIVADOS");
      channel = random(2, 81);
    } else {
      Serial.println("Modo: Canal individual");
      channel = current_channel;
    }
    char selected_str[32];
    lv_dropdown_get_selected_str(ui_TransmissionSpeedDropdown, selected_str, sizeof(selected_str));
    Serial.print("Velocidad seleccionada: ");
    Serial.println(selected_str);
    
  }
  bool estado = lv_obj_has_state(ui_initbutton, LV_STATE_CHECKED);
    if (estado) {
      radio.setChannel(channel);
      if (radio.writeFast(&payload, sizeof(payload))) {
        radio.txStandBy(); 
      } else {
        delayMicroseconds(10);  
      }
      char send[64];
      sprintf(send, "Enviado canal:%d\n", channel);
      Serial.println(send);
      lv_textarea_add_text(ui_logtextbox, send);
    } else {
        Serial.println("Botón desactivado");
    }
  


}



