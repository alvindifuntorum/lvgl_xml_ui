/**
 * @file climate_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "climate_gen.h"
#include "../../../examples.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * climate_create(lv_obj_t * parent, const char * zone1_name, const char * zone2_name, const char * zone3_name, const char * zone4_name, const char * zone5_name, const void * mode_icon, const char * mode_label, const void * fanspeed_icon, const char * fanspeed_label)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_room_temp;
    static lv_style_t style_target_temp;
    static lv_style_t style_temp_unit;
    static lv_style_t style_arc_indicator;
    static lv_style_t style_arc_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_height(&style_base, lv_pct(100));
        lv_style_set_flex_grow(&style_base, 1);
        lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_base, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_shadow_color(&style_base, lv_color_hex3(0x000));
        lv_style_set_shadow_offset_y(&style_base, 2);
        lv_style_set_shadow_opa(&style_base, 30);
        lv_style_set_shadow_spread(&style_base, 1);
        lv_style_set_shadow_width(&style_base, UNIT_SM);

        lv_style_init(&style_room_temp);
        lv_style_set_text_font(&style_room_temp, geist_regular_32);
        lv_style_set_text_color(&style_room_temp, lv_color_hex(0x929293));

        lv_style_init(&style_target_temp);
        lv_style_set_text_font(&style_target_temp, geist_light_60);
        lv_style_set_text_color(&style_target_temp, lv_color_hex(0x333333));

        lv_style_init(&style_temp_unit);
        lv_style_set_text_font(&style_temp_unit, geist_regular_14);
        lv_style_set_text_color(&style_temp_unit, lv_color_hex(0x929293));

        lv_style_init(&style_arc_indicator);
        lv_style_set_arc_width(&style_arc_indicator, 12);
        lv_style_set_arc_color(&style_arc_indicator, lv_color_hex(0x45AFDB));

        lv_style_init(&style_arc_main);
        lv_style_set_arc_width(&style_arc_main, 12);
        lv_style_set_arc_color(&style_arc_main, lv_color_hex(0xD0D0D0));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "climate_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_base, 0);
    lv_obj_t * zone_header = lv_tabview_create(lv_obj_0);
    lv_obj_set_name(zone_header, "zone_header");
    lv_obj_set_style_width(zone_header, lv_pct(100), 0);
    lv_tabview_set_tab_bar_position(zone_header, LV_DIR_TOP);
    lv_obj_t * tab_zone1 = lv_tabview_add_tab(zone_header, zone1_name);
    lv_obj_set_name(tab_zone1, "tab_zone1");
    lv_obj_t * tab_zone2 = lv_tabview_add_tab(zone_header, zone2_name);
    lv_obj_set_name(tab_zone2, "tab_zone2");
    lv_obj_t * tab_zone3 = lv_tabview_add_tab(zone_header, zone3_name);
    lv_obj_set_name(tab_zone3, "tab_zone3");
    lv_obj_t * tab_zone4 = lv_tabview_add_tab(zone_header, zone4_name);
    lv_obj_set_name(tab_zone4, "tab_zone4");
    lv_obj_t * tab_zone5 = lv_tabview_add_tab(zone_header, zone5_name);
    lv_obj_set_name(tab_zone5, "tab_zone5");

    lv_obj_t * target_temp_arc = lv_arc_create(lv_obj_0);
    lv_obj_set_name(target_temp_arc, "target_temp_arc");
    lv_arc_bind_value(target_temp_arc, &thermostat_temp);
    lv_arc_set_min_value(target_temp_arc, 16);
    lv_arc_set_max_value(target_temp_arc, 31);
    lv_obj_set_width(target_temp_arc, lv_pct(86));
    lv_obj_set_height(target_temp_arc, lv_pct(68));
    lv_obj_set_align(target_temp_arc, LV_ALIGN_CENTER);
    lv_obj_add_style(target_temp_arc, &style_arc_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(target_temp_arc, &style_arc_main, LV_PART_MAIN);
    lv_obj_t * arc_content = column_create(target_temp_arc);
    lv_obj_set_name(arc_content, "arc_content");
    lv_obj_set_style_width(arc_content, LV_SIZE_CONTENT, 0);
    lv_obj_set_style_height(arc_content, LV_SIZE_CONTENT, 0);
    lv_obj_set_style_flex_main_place(arc_content, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(arc_content, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_row(arc_content, UNIT_XL, 0);
    lv_obj_set_align(arc_content, LV_ALIGN_CENTER);
    lv_obj_t * room_temp_row = row_create(arc_content);
    lv_obj_set_name(room_temp_row, "room_temp_row");
    lv_obj_set_style_flex_main_place(room_temp_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(room_temp_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_column(room_temp_row, UNIT_SM, 0);
    lv_obj_t * thermometer_icon = lv_image_create(room_temp_row);
    lv_obj_set_name(thermometer_icon, "thermometer_icon");
    lv_image_set_src(thermometer_icon, icon_heart);

    lv_obj_t * room_temp_label = lv_label_create(room_temp_row);
    lv_obj_set_name(room_temp_label, "room_temp_label");
    lv_label_bind_text(room_temp_label, &room_temp, "%d°C");
    lv_obj_add_style(room_temp_label, &style_room_temp, 0);

    lv_obj_t * target_temp_row = row_create(arc_content);
    lv_obj_set_name(target_temp_row, "target_temp_row");
    lv_obj_set_style_flex_main_place(target_temp_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(target_temp_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_t * temp_adjust_icon = lv_image_create(target_temp_row);
    lv_obj_set_name(temp_adjust_icon, "temp_adjust_icon");
    lv_image_set_src(temp_adjust_icon, icon_heart);

    lv_obj_t * target_temp_label = lv_label_create(target_temp_row);
    lv_obj_set_name(target_temp_label, "target_temp_label");
    lv_label_bind_text(target_temp_label, &thermostat_temp, "%d");
    lv_obj_add_style(target_temp_label, &style_target_temp, 0);

    lv_obj_t * temp_unit_label = lv_label_create(target_temp_row);
    lv_obj_set_name(temp_unit_label, "temp_unit_label");
    lv_label_set_text(temp_unit_label, "°C");
    lv_obj_add_style(temp_unit_label, &style_temp_unit, 0);

    lv_obj_t * mode_icons_row = row_create(arc_content);
    lv_obj_set_name(mode_icons_row, "mode_icons_row");
    lv_obj_set_style_flex_main_place(mode_icons_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(mode_icons_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_column(mode_icons_row, UNIT_SM, 0);
    lv_obj_t * sleep_icon = lv_image_create(mode_icons_row);
    lv_obj_set_name(sleep_icon, "sleep_icon");
    lv_image_set_src(sleep_icon, icon_heart);

    lv_obj_t * eco_icon = lv_image_create(mode_icons_row);
    lv_obj_set_name(eco_icon, "eco_icon");
    lv_image_set_src(eco_icon, icon_heart);

    lv_obj_t * bottom_buttons = row_create(lv_obj_0);
    lv_obj_set_name(bottom_buttons, "bottom_buttons");
    lv_obj_set_style_flex_main_place(bottom_buttons, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(bottom_buttons, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_column(bottom_buttons, UNIT_SM, 0);
    lv_obj_t * mode_button = icon_label_button_create(bottom_buttons, mode_icon, mode_label);
    lv_obj_set_name(mode_button, "mode_button");

    lv_obj_t * fanspeed_button = icon_label_button_create(bottom_buttons, fanspeed_icon, fanspeed_label);
    lv_obj_set_name(fanspeed_button, "fanspeed_button");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

