/**
 * @file parameter_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "parameter_gen.h"
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

lv_obj_t * parameter_create(lv_obj_t * parent, const char * title, const void * icon, const char * parameter)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_left;
    static lv_style_t style_right;
    static lv_style_t style_switch_main;
    static lv_style_t style_switch_main_dark;
    static lv_style_t style_switch_indicator;
    static lv_style_t style_switch_indicator_dark;
    static lv_style_t style_switch_knob;
    static lv_style_t style_switch_knob_checked;
    static lv_style_t style_switch_knob_dark;
    static lv_style_t style_switch_knob_checked_dark;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_base);
        lv_style_set_width(&style_base, lv_pct(100));
        lv_style_set_height(&style_base, LV_SIZE_CONTENT);
        lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
        lv_style_set_pad_all(&style_base, UNIT_MD);
        lv_style_set_flex_flow(&style_base, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_main_place(&style_base, LV_FLEX_ALIGN_SPACE_BETWEEN);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_radius(&style_base, UNIT_SM);
        lv_style_set_shadow_color(&style_base, lv_color_hex3(0x000));
        lv_style_set_shadow_offset_y(&style_base, 4);
        lv_style_set_shadow_opa(&style_base, 64);
        lv_style_set_shadow_spread(&style_base, 0);
        lv_style_set_shadow_width(&style_base, 2);

        lv_style_init(&style_left);
        lv_style_set_height(&style_left, LV_SIZE_CONTENT);
        lv_style_set_width(&style_left, LV_SIZE_CONTENT);
        lv_style_set_layout(&style_left, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_left, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_cross_place(&style_left, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&style_left, UNIT_SM);

        lv_style_init(&style_right);
        lv_style_set_height(&style_right, LV_SIZE_CONTENT);
        lv_style_set_width(&style_right, LV_SIZE_CONTENT);
        lv_style_set_layout(&style_right, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_right, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_cross_place(&style_right, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_main_place(&style_right, LV_FLEX_ALIGN_END);
        lv_style_set_pad_column(&style_right, UNIT_SM);

        lv_style_init(&style_switch_main);
        lv_style_set_radius(&style_switch_main, 10);
        lv_style_set_bg_color(&style_switch_main, SURFACE_PRIMARY_LIGHT);
        lv_style_set_bg_opa(&style_switch_main, (255 * 0 / 100));
        lv_style_set_border_width(&style_switch_main, 2);
        lv_style_set_border_color(&style_switch_main, lv_color_hex3(0x000));

        lv_style_init(&style_switch_main_dark);
        lv_style_set_bg_color(&style_switch_main_dark, SURFACE_PRIMARY_DARK);

        lv_style_init(&style_switch_indicator);
        lv_style_set_radius(&style_switch_indicator, 8);
        lv_style_set_bg_color(&style_switch_indicator, SURFACE_PRIMARY_LIGHT);
        lv_style_set_border_width(&style_switch_indicator, 0);
        lv_style_set_bg_opa(&style_switch_indicator, (255 * 100 / 100));

        lv_style_init(&style_switch_indicator_dark);
        lv_style_set_bg_color(&style_switch_indicator_dark, SURFACE_PRIMARY_DARK);

        lv_style_init(&style_switch_knob);
        lv_style_set_radius(&style_switch_knob, 4);
        lv_style_set_pad_top(&style_switch_knob, -6);
        lv_style_set_pad_bottom(&style_switch_knob, -6);
        lv_style_set_pad_left(&style_switch_knob, -6);
        lv_style_set_pad_right(&style_switch_knob, -6);
        lv_style_set_shadow_opa(&style_switch_knob, 0);
        lv_style_set_bg_color(&style_switch_knob, lv_color_hex3(0x000));
        lv_style_set_border_width(&style_switch_knob, 0);

        lv_style_init(&style_switch_knob_checked);
        lv_style_set_bg_color(&style_switch_knob_checked, BG_PRIMARY_LIGHT);
        lv_style_set_bg_opa(&style_switch_knob_checked, (255 * 100 / 100));

        lv_style_init(&style_switch_knob_dark);
        lv_style_set_bg_color(&style_switch_knob_dark, lv_color_hex3(0x000));

        lv_style_init(&style_switch_knob_checked_dark);
        lv_style_set_bg_color(&style_switch_knob_checked_dark, BG_PRIMARY_DARK);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "parameter_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_base, 0);
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_remove_style_all(lv_obj_1);
    lv_obj_add_style(lv_obj_1, &style_left, 0);
    icon_button_create(lv_obj_1, icon);

    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_set_text(lv_label_0, title);

    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_0);
    lv_obj_remove_style_all(lv_obj_2);
    lv_obj_add_style(lv_obj_2, &style_right, 0);
    lv_obj_t * parameter_label = lv_label_create(lv_obj_2);
    lv_obj_set_name(parameter_label, "parameter_label");
    lv_label_set_text(parameter_label, parameter);

    lv_obj_t * toggle = lv_switch_create(lv_obj_2);
    lv_obj_set_name(toggle, "toggle");
    lv_obj_set_width(toggle, 44);
    lv_obj_set_height(toggle, 34);
    lv_obj_add_style(toggle, &style_switch_main, LV_PART_MAIN);
    lv_obj_add_style(toggle, &style_switch_indicator, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_add_style(toggle, &style_switch_knob, LV_PART_KNOB);
    lv_obj_add_style(toggle, &style_switch_knob_checked, LV_PART_KNOB | LV_STATE_CHECKED);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

