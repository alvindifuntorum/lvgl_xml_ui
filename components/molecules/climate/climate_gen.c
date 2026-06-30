/**
 * @file climate_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "climate_gen.h"
#include "../../../hmi_ui.h"

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

lv_obj_t *climate_create(lv_obj_t *parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;

    static bool style_inited = false;

    if (!style_inited)
    {
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

        style_inited = true;
    }

    lv_obj_t *lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "climate_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_base, 0);
    lv_obj_t *climate_content = column_create(lv_obj_0);
    lv_obj_set_name(climate_content, "climate_content");
    lv_obj_set_style_width(climate_content, lv_pct(100), 0);
    lv_obj_set_style_height(climate_content, lv_pct(100), 0);
    lv_obj_set_style_flex_grow(climate_content, 1, 0);
    lv_obj_set_style_layout(climate_content, LV_LAYOUT_FLEX, 0);
    lv_obj_set_style_flex_flow(climate_content, LV_FLEX_FLOW_COLUMN, 0);
    lv_obj_set_style_flex_main_place(climate_content, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(climate_content, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_row(climate_content, UNIT_SM, 0);
    lv_obj_t *target_temp_arc = lv_arc_create(climate_content);
    lv_obj_set_name(target_temp_arc, "target_temp_arc");
    lv_arc_set_value(target_temp_arc, 20);
    lv_arc_set_min_value(target_temp_arc, 16);
    lv_arc_set_max_value(target_temp_arc, 31);
    lv_obj_set_width(target_temp_arc, lv_pct(86));
    lv_obj_set_height(target_temp_arc, lv_pct(76));
    lv_obj_set_align(target_temp_arc, LV_ALIGN_CENTER);
    lv_obj_t *internal_temp_label = lv_label_create(target_temp_arc);
    lv_obj_set_name(internal_temp_label, "internal_temp_label");
    lv_label_set_text(internal_temp_label, "--itemp");
    lv_obj_set_align(internal_temp_label, LV_ALIGN_CENTER);
    lv_obj_set_y(internal_temp_label, -18);

    lv_obj_t *target_temp_label = lv_label_create(target_temp_arc);
    lv_obj_set_name(target_temp_label, "target_temp_label");
    lv_label_set_text(target_temp_label, "--ttemp");
    lv_obj_set_align(target_temp_label, LV_ALIGN_CENTER);
    lv_obj_set_y(target_temp_label, 4);

    lv_obj_t *sleep_label = lv_label_create(target_temp_arc);
    lv_obj_set_name(sleep_label, "sleep_label");
    lv_label_set_text(sleep_label, "--sleep");
    lv_obj_set_align(sleep_label, LV_ALIGN_CENTER);
    lv_obj_set_y(sleep_label, 26);

    lv_obj_t *row_0 = row_create(climate_content);
    lv_obj_set_style_flex_main_place(row_0, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_cross_place(row_0, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_column(row_0, UNIT_SM, 0);
    lv_obj_t *mode_button = icon_label_button_create(row_0, icon_menu, "Auto");
    lv_obj_set_name(mode_button, "mode_button");

    lv_obj_t *fanspeed_button = icon_label_button_create(row_0, icon_menu, "Auto");
    lv_obj_set_name(fanspeed_button, "fanspeed_button");

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
