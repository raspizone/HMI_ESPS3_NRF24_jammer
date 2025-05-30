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
    lv_obj_set_x(ui_initsw, 309);
    lv_obj_set_y(ui_initsw, 183);
    lv_obj_set_align(ui_initsw, LV_ALIGN_CENTER);

    ui_channeldp = lv_dropdown_create(ui_Screen1);
    lv_obj_set_width(ui_channeldp, 150);
    lv_obj_set_height(ui_channeldp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_channeldp, -123);
    lv_obj_set_y(ui_channeldp, -15);
    lv_obj_set_align(ui_channeldp, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_channeldp, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_logtx = lv_textarea_create(ui_Screen1);
    lv_obj_set_width(ui_logtx, 150);
    lv_obj_set_height(ui_logtx, 331);
    lv_obj_set_x(ui_logtx, 278);
    lv_obj_set_y(ui_logtx, -36);
    lv_obj_set_align(ui_logtx, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(ui_logtx, "Placeholder...");

    ui_initlb = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_initlb, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_initlb, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_initlb, 307);
    lv_obj_set_y(ui_initlb, 153);
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
    lv_label_set_text(ui_scanlb, "SCAN");

}
