/**
 * @file icon_label_button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "icon_label_button_gen.h"
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

lv_obj_t *icon_label_button_create(lv_obj_t *parent, const void *icon, const char *label)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;

    static bool style_inited = false;

    if (!style_inited)
    {
        lv_style_init(&style_base);
        lv_style_set_width(&style_base, LV_SIZE_CONTENT);
        lv_style_set_height(&style_base, LV_SIZE_CONTENT);
        lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_base, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_main_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_base, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_all(&style_base, UNIT_SM);
        lv_style_set_pad_column(&style_base, UNIT_SM);
        lv_style_set_radius(&style_base, UNIT_MD);
        lv_style_set_bg_opa(&style_base, (255 * 100 / 100));
        lv_style_set_bg_color(&style_base, BG_SECONDARY_LIGHT);
        lv_style_set_text_color(&style_base, TEXT_ON_SURFACE_PRIMARY_LIGHT);
        lv_style_set_border_width(&style_base, 0);
        lv_style_set_shadow_color(&style_base, lv_color_hex3(0x222));
        lv_style_set_shadow_offset_y(&style_base, 2);
        lv_style_set_shadow_opa(&style_base, 30);
        lv_style_set_shadow_spread(&style_base, 1);
        lv_style_set_shadow_width(&style_base, UNIT_SM);

        style_inited = true;
    }

    lv_obj_t *lv_button_0 = lv_button_create(parent);
    lv_obj_set_name_static(lv_button_0, "icon_label_button_#");

    lv_obj_remove_style_all(lv_button_0);
    lv_obj_add_style(lv_button_0, &style_base, 0);
    lv_obj_t *image = lv_image_create(lv_button_0);
    lv_obj_set_name(image, "image");
    lv_image_set_src(image, icon);
    lv_obj_set_align(image, LV_ALIGN_CENTER);

    lv_obj_t *text = lv_label_create(lv_button_0);
    lv_obj_set_name(text, "text");
    lv_label_set_text(text, label);
    lv_obj_set_style_text_color(text, lv_color_hex3(0x000), 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_button_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
