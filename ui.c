// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
void ui_event_scanbt(lv_event_t * e);
lv_obj_t * ui_scanbt;
void ui_event_initbutton(lv_event_t * e);
lv_obj_t * ui_initbutton;
lv_obj_t * ui_logtextbox;
lv_obj_t * ui_initlb;
lv_obj_t * ui_titlelb;
lv_obj_t * ui_Label4;
lv_obj_t * ui_SliderSelectChannel;
lv_obj_t * ui_allchannelcheckbox;
lv_obj_t * ui_TransmissionSpeedDropdown;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Chart1;
lv_obj_t * ui_ScanBleResult;
lv_obj_t * ui_channel;
lv_obj_t * ui_Label2;
// CUSTOM VARIABLES

// EVENTS
lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_scanbt(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        initscanble(e);
    }
}

void ui_event_initbutton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        initjammer(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}
