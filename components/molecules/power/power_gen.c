/**
 * @file power_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "power_gen.h"
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

lv_obj_t * power_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_indicator_text;
    static lv_style_t style_warning_text;
    static lv_style_t style_main_text;
    static lv_style_t style_sub_text;
    static lv_style_t style_hist_green;
    static lv_style_t style_hist_yellow;

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

        lv_style_init(&style_indicator_text);
        lv_style_set_text_color(&style_indicator_text, lv_color_hex(0x527B35));

        lv_style_init(&style_warning_text);
        lv_style_set_text_color(&style_warning_text, lv_color_hex(0xBD9D03));

        lv_style_init(&style_main_text);
        lv_style_set_text_color(&style_main_text, lv_color_hex(0x333333));

        lv_style_init(&style_sub_text);
        lv_style_set_text_color(&style_sub_text, lv_color_hex(0x929293));

        lv_style_init(&style_hist_green);
        lv_style_set_bg_opa(&style_hist_green, (255 * 100 / 100));
        lv_style_set_bg_color(&style_hist_green, lv_color_hex(0x83C157));

        lv_style_init(&style_hist_yellow);
        lv_style_set_bg_opa(&style_hist_yellow, (255 * 100 / 100));
        lv_style_set_bg_color(&style_hist_yellow, lv_color_hex(0xF9D33E));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "power_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_base, 0);
    lv_obj_t * top_row = row_create(lv_obj_0);
    lv_obj_set_name(top_row, "top_row");
    lv_obj_set_width(top_row, lv_pct(100));
    lv_obj_set_style_flex_main_place(top_row, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_set_style_flex_cross_place(top_row, LV_FLEX_ALIGN_START, 0);
    lv_obj_set_style_pad_left(top_row, UNIT_LG, 0);
    lv_obj_set_style_pad_right(top_row, UNIT_LG, 0);
    lv_obj_set_style_pad_top(top_row, UNIT_SM, 0);
    lv_obj_t * column_0 = column_create(top_row);
    lv_obj_set_style_pad_row(column_0, UNIT_2XS, 0);
    lv_obj_set_style_flex_cross_place(column_0, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_t * solar_current_label = lv_label_create(column_0);
    lv_obj_set_name(solar_current_label, "solar_current_label");
    lv_label_set_text(solar_current_label, "11,2 A");
    lv_obj_add_style(solar_current_label, &style_indicator_text, 0);

    lv_obj_t * solar_icon = lv_image_create(column_0);
    lv_obj_set_name(solar_icon, "solar_icon");
    lv_image_set_src(solar_icon, icon_solar_panel);

    lv_obj_t * row_0 = row_create(top_row);
    lv_obj_set_style_pad_column(row_0, UNIT_2XS, 0);
    lv_obj_set_style_flex_cross_place(row_0, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_top(row_0, UNIT_2XS, 0);
    lv_obj_t * shore_icon = lv_image_create(row_0);
    lv_obj_set_name(shore_icon, "shore_icon");
    lv_image_set_src(shore_icon, icon_main_right);

    lv_obj_t * shore_current_label = lv_label_create(row_0);
    lv_obj_set_name(shore_current_label, "shore_current_label");
    lv_label_set_text(shore_current_label, "12,3 A");
    lv_obj_add_style(shore_current_label, &style_indicator_text, 0);

    lv_obj_t * column_1 = column_create(top_row);
    lv_obj_set_style_pad_row(column_1, UNIT_2XS, 0);
    lv_obj_set_style_flex_cross_place(column_1, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_t * alternator_current_label = lv_label_create(column_1);
    lv_obj_set_name(alternator_current_label, "alternator_current_label");
    lv_label_set_text(alternator_current_label, "13,4 A");
    lv_obj_add_style(alternator_current_label, &style_indicator_text, 0);

    lv_obj_t * alternator_icon = lv_image_create(column_1);
    lv_obj_set_name(alternator_icon, "alternator_icon");
    lv_image_set_src(alternator_icon, icon_inverter);

    lv_obj_t * state_of_charge_arc = lv_arc_create(lv_obj_0);
    lv_obj_set_name(state_of_charge_arc, "state_of_charge_arc");
    lv_arc_set_value(state_of_charge_arc, 75);
    lv_arc_set_min_value(state_of_charge_arc, 0);
    lv_arc_set_max_value(state_of_charge_arc, 100);
    lv_obj_set_width(state_of_charge_arc, lv_pct(84));
    lv_obj_set_height(state_of_charge_arc, lv_pct(70));
    lv_obj_set_align(state_of_charge_arc, LV_ALIGN_CENTER);
    lv_obj_t * center_content = column_create(state_of_charge_arc);
    lv_obj_set_name(center_content, "center_content");
    lv_obj_set_style_width(center_content, LV_SIZE_CONTENT, 0);
    lv_obj_set_style_height(center_content, LV_SIZE_CONTENT, 0);
    lv_obj_set_style_flex_main_place(center_content, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(center_content, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_row(center_content, UNIT_2XS, 0);
    lv_obj_t * temp_label = lv_label_create(center_content);
    lv_obj_set_name(temp_label, "temp_label");
    lv_label_set_text(temp_label, "+ 41 A");
    lv_obj_add_style(temp_label, &style_indicator_text, 0);

    lv_obj_t * row_1 = row_create(center_content);
    lv_obj_set_style_flex_main_place(row_1, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(row_1, LV_FLEX_ALIGN_START, 0);
    lv_obj_set_style_pad_column(row_1, UNIT_2XS, 0);
    lv_obj_t * capacity_remain_label = lv_label_create(row_1);
    lv_obj_set_name(capacity_remain_label, "capacity_remain_label");
    lv_label_set_text(capacity_remain_label, "75");
    lv_obj_add_style(capacity_remain_label, &style_main_text, 0);

    lv_obj_t * capacity_unit_label = lv_label_create(row_1);
    lv_obj_set_name(capacity_unit_label, "capacity_unit_label");
    lv_label_set_text(capacity_unit_label, "%");
    lv_obj_set_style_pad_top(capacity_unit_label, UNIT_SM, 0);
    lv_obj_add_style(capacity_unit_label, &style_sub_text, 0);

    lv_obj_t * histogram_top = row_create(center_content);
    lv_obj_set_name(histogram_top, "histogram_top");
    lv_obj_set_style_pad_column(histogram_top, 2, 0);
    lv_obj_set_style_flex_cross_place(histogram_top, LV_FLEX_ALIGN_END, 0);
    lv_obj_set_style_pad_top(histogram_top, UNIT_SM, 0);
    lv_obj_t * div_0 = div_create(histogram_top);
    lv_obj_set_width(div_0, 2);
    lv_obj_set_height(div_0, 18);
    lv_obj_set_style_bg_opa(div_0, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_0, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_1 = div_create(histogram_top);
    lv_obj_set_width(div_1, 2);
    lv_obj_set_height(div_1, 22);
    lv_obj_set_style_bg_opa(div_1, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_1, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_2 = div_create(histogram_top);
    lv_obj_set_width(div_2, 2);
    lv_obj_set_height(div_2, 26);
    lv_obj_set_style_bg_opa(div_2, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_2, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_3 = div_create(histogram_top);
    lv_obj_set_width(div_3, 2);
    lv_obj_set_height(div_3, 20);
    lv_obj_set_style_bg_opa(div_3, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_3, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_4 = div_create(histogram_top);
    lv_obj_set_width(div_4, 2);
    lv_obj_set_height(div_4, 14);
    lv_obj_set_style_bg_opa(div_4, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_4, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_5 = div_create(histogram_top);
    lv_obj_set_width(div_5, 2);
    lv_obj_set_height(div_5, 10);
    lv_obj_set_style_bg_opa(div_5, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_5, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_6 = div_create(histogram_top);
    lv_obj_set_width(div_6, 2);
    lv_obj_set_height(div_6, 12);
    lv_obj_set_style_bg_opa(div_6, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_6, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_7 = div_create(histogram_top);
    lv_obj_set_width(div_7, 2);
    lv_obj_set_height(div_7, 14);
    lv_obj_set_style_bg_opa(div_7, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_7, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_8 = div_create(histogram_top);
    lv_obj_set_width(div_8, 2);
    lv_obj_set_height(div_8, 18);
    lv_obj_set_style_bg_opa(div_8, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_8, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_9 = div_create(histogram_top);
    lv_obj_set_width(div_9, 2);
    lv_obj_set_height(div_9, 14);
    lv_obj_set_style_bg_opa(div_9, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_9, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_10 = div_create(histogram_top);
    lv_obj_set_width(div_10, 2);
    lv_obj_set_height(div_10, 10);
    lv_obj_set_style_bg_opa(div_10, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_10, lv_color_hex(0x83C157), 0);

    lv_obj_t * div_11 = div_create(center_content);
    lv_obj_set_width(div_11, lv_pct(100));
    lv_obj_set_height(div_11, 1);
    lv_obj_set_style_bg_opa(div_11, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_11, lv_color_hex(0xE2E3E2), 0);

    lv_obj_t * histogram_bottom = row_create(center_content);
    lv_obj_set_name(histogram_bottom, "histogram_bottom");
    lv_obj_set_style_pad_column(histogram_bottom, 2, 0);
    lv_obj_set_style_flex_cross_place(histogram_bottom, LV_FLEX_ALIGN_START, 0);
    lv_obj_t * div_12 = div_create(histogram_bottom);
    lv_obj_set_width(div_12, 2);
    lv_obj_set_height(div_12, 4);
    lv_obj_set_style_bg_opa(div_12, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_12, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_13 = div_create(histogram_bottom);
    lv_obj_set_width(div_13, 2);
    lv_obj_set_height(div_13, 8);
    lv_obj_set_style_bg_opa(div_13, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_13, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_14 = div_create(histogram_bottom);
    lv_obj_set_width(div_14, 2);
    lv_obj_set_height(div_14, 16);
    lv_obj_set_style_bg_opa(div_14, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_14, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_15 = div_create(histogram_bottom);
    lv_obj_set_width(div_15, 2);
    lv_obj_set_height(div_15, 28);
    lv_obj_set_style_bg_opa(div_15, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_15, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_16 = div_create(histogram_bottom);
    lv_obj_set_width(div_16, 2);
    lv_obj_set_height(div_16, 34);
    lv_obj_set_style_bg_opa(div_16, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_16, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_17 = div_create(histogram_bottom);
    lv_obj_set_width(div_17, 2);
    lv_obj_set_height(div_17, 30);
    lv_obj_set_style_bg_opa(div_17, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_17, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_18 = div_create(histogram_bottom);
    lv_obj_set_width(div_18, 2);
    lv_obj_set_height(div_18, 24);
    lv_obj_set_style_bg_opa(div_18, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_18, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_19 = div_create(histogram_bottom);
    lv_obj_set_width(div_19, 2);
    lv_obj_set_height(div_19, 16);
    lv_obj_set_style_bg_opa(div_19, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_19, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_20 = div_create(histogram_bottom);
    lv_obj_set_width(div_20, 2);
    lv_obj_set_height(div_20, 10);
    lv_obj_set_style_bg_opa(div_20, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_20, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_21 = div_create(histogram_bottom);
    lv_obj_set_width(div_21, 2);
    lv_obj_set_height(div_21, 6);
    lv_obj_set_style_bg_opa(div_21, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_21, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * div_22 = div_create(histogram_bottom);
    lv_obj_set_width(div_22, 2);
    lv_obj_set_height(div_22, 2);
    lv_obj_set_style_bg_opa(div_22, (255 * 100 / 100), 0);
    lv_obj_set_style_bg_color(div_22, lv_color_hex(0xF9D33E), 0);

    lv_obj_t * bottom_row = row_create(lv_obj_0);
    lv_obj_set_name(bottom_row, "bottom_row");
    lv_obj_set_width(bottom_row, lv_pct(100));
    lv_obj_set_style_flex_main_place(bottom_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(bottom_row, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_column(bottom_row, UNIT_SM, 0);
    lv_obj_set_style_pad_bottom(bottom_row, UNIT_SM, 0);
    lv_obj_t * battery_icon = lv_image_create(bottom_row);
    lv_obj_set_name(battery_icon, "battery_icon");
    lv_image_set_src(battery_icon, icon_battery_energy);

    lv_obj_t * battery_current_label = lv_label_create(bottom_row);
    lv_obj_set_name(battery_current_label, "battery_current_label");
    lv_label_set_text(battery_current_label, "11,2 A");
    lv_obj_add_style(battery_current_label, &style_warning_text, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

