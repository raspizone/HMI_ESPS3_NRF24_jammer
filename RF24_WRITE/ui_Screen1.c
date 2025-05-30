// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.1
// LVGL version: 8.3.11
// Project name: SquareLine_Project

#include "ui.h"

void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_add_state(ui_Screen1, LV_STATE_CHECKED);       /// States
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_scanbt = lv_btn_create(ui_Screen1);
    lv_obj_set_width(ui_scanbt, 100);
    lv_obj_set_height(ui_scanbt, 26);
    lv_obj_set_x(ui_scanbt, -295);
    lv_obj_set_y(ui_scanbt, -68);
    lv_obj_set_align(ui_scanbt, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_scanbt, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_scanbt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_scandp = lv_dropdown_create(ui_Screen1);
    lv_obj_set_width(ui_scandp, 150);
    lv_obj_set_height(ui_scandp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scandp, -296);
    lv_obj_set_y(ui_scandp, -16);
    lv_obj_set_align(ui_scandp, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_scandp, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_initsw = lv_switch_create(ui_Screen1);
    lv_obj_set_width(ui_initsw, 50);
    lv_obj_set_height(ui_initsw, 25);
    lv_obj_set_x(ui_initsw, -283);
    lv_obj_set_y(ui_initsw, 172);
    lv_obj_set_align(ui_initsw, LV_ALIGN_CENTER);

    ui_logtx = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_logtx, 150);
    lv_obj_set_height(ui_logtx, 298);
    lv_obj_set_x(ui_logtx, 276);
    lv_obj_set_y(ui_logtx, 70);
    lv_obj_set_align(ui_logtx, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_logtx, "Placeholder...");

    ui_initlb = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_initlb, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_initlb, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_initlb, -347);
    lv_obj_set_y(ui_initlb, 172);
    lv_obj_set_align(ui_initlb, LV_ALIGN_CENTER);
    lv_label_set_text(ui_initlb, "INIT");

    ui_titlelb = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_titlelb, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_titlelb, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_titlelb, -92);
    lv_obj_set_y(ui_titlelb, -187);
    lv_obj_set_align(ui_titlelb, LV_ALIGN_CENTER);
    lv_label_set_text(ui_titlelb, "NRF24 BLUETOOTH JAMMER");
    lv_obj_set_style_text_font(ui_titlelb, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_titlelb, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_EDITED);

    ui_scanlb = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_scanlb, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_scanlb, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_scanlb, -295);
    lv_obj_set_y(ui_scanlb, -69);
    lv_obj_set_align(ui_scanlb, LV_ALIGN_CENTER);
    lv_label_set_text(ui_scanlb, "SCAN BLE");

    ui_Label4 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label4, -122);
    lv_obj_set_y(ui_Label4, -66);
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "SELECT CHANNEL");

    ui_Slider1 = lv_slider_create(ui_Screen1);
    lv_slider_set_range(ui_Slider1, 0, 40);
    lv_slider_set_value(ui_Slider1, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Slider1) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Slider1, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Slider1, 150);
    lv_obj_set_height(ui_Slider1, 10);
    lv_obj_set_x(ui_Slider1, -106);
    lv_obj_set_y(ui_Slider1, -14);
    lv_obj_set_align(ui_Slider1, LV_ALIGN_CENTER);

    ui_Checkbox1 = lv_checkbox_create(ui_Screen1);
    lv_checkbox_set_text(ui_Checkbox1, "ALL CHANNELS");
    lv_obj_set_width(ui_Checkbox1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Checkbox1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Checkbox1, -109);
    lv_obj_set_y(ui_Checkbox1, 20);
    lv_obj_set_align(ui_Checkbox1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Checkbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_Dropdown4 = lv_dropdown_create(ui_Screen1);
    lv_obj_set_width(ui_Dropdown4, 150);
    lv_obj_set_height(ui_Dropdown4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Dropdown4, 80);
    lv_obj_set_y(ui_Dropdown4, -12);
    lv_obj_set_align(ui_Dropdown4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Dropdown4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_Label5 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label5, 74);
    lv_obj_set_y(ui_Label5, -65);
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "TRANSMISSION SPEED");

    ui_Label6 = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label6, 268);
    lv_obj_set_y(ui_Label6, -97);
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "LOG");

    ui_Chart1 = lv_chart_create(ui_Screen1);
    lv_obj_set_width(ui_Chart1, 200);
    lv_obj_set_height(ui_Chart1, 100);
    lv_obj_set_x(ui_Chart1, -3);
    lv_obj_set_y(ui_Chart1, 133);
    lv_obj_set_align(ui_Chart1, LV_ALIGN_CENTER);
    lv_chart_set_type(ui_Chart1, LV_CHART_TYPE_LINE);
    lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_PRIMARY_X, 10, 5, 5, 2, true, 50);
    lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 2, true, 50);
    lv_chart_set_axis_tick(ui_Chart1, LV_CHART_AXIS_SECONDARY_Y, 10, 5, 5, 2, true, 25);
    lv_chart_series_t * ui_Chart1_series_1 = lv_chart_add_series(ui_Chart1, lv_color_hex(0x808080),
                                                                 LV_CHART_AXIS_PRIMARY_Y);
    static lv_coord_t ui_Chart1_series_1_array[] = { 0, 10, 20, 40, 80, 80, 40, 20, 10, 0 };
    lv_chart_set_ext_y_array(ui_Chart1, ui_Chart1_series_1, ui_Chart1_series_1_array);

}
