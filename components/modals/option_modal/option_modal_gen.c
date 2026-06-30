/**
 * @file option_modal_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "option_modal_gen.h"
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

lv_obj_t * option_modal_create(lv_obj_t * parent, const char * title, const char * options, int32_t selected, const void * close, const void * confirm)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_backdrop;
    static lv_style_t style_side;
    static lv_style_t style_action_btn;
    static lv_style_t style_modal;
    static lv_style_t style_title_bar;
    static lv_style_t style_title;
    static lv_style_t style_roller;
    static lv_style_t style_roller_selected;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_backdrop);
        lv_style_set_width(&style_backdrop, lv_pct(100));
        lv_style_set_height(&style_backdrop, lv_pct(100));
        lv_style_set_layout(&style_backdrop, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_backdrop, LV_FLEX_FLOW_ROW);
        lv_style_set_flex_main_place(&style_backdrop, LV_FLEX_ALIGN_SPACE_BETWEEN);
        lv_style_set_flex_cross_place(&style_backdrop, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_all(&style_backdrop, 8);
        lv_style_set_bg_color(&style_backdrop, lv_color_hex(0x000000));
        lv_style_set_bg_opa(&style_backdrop, 178);

        lv_style_init(&style_side);
        lv_style_set_width(&style_side, LV_SIZE_CONTENT);
        lv_style_set_height(&style_side, lv_pct(100));
        lv_style_set_layout(&style_side, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_side, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&style_side, LV_FLEX_ALIGN_END);
        lv_style_set_flex_cross_place(&style_side, LV_FLEX_ALIGN_CENTER);

        lv_style_init(&style_action_btn);
        lv_style_set_width(&style_action_btn, 66);
        lv_style_set_height(&style_action_btn, 66);
        lv_style_set_bg_color(&style_action_btn, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_action_btn, 255);
        lv_style_set_border_width(&style_action_btn, 1);
        lv_style_set_border_color(&style_action_btn, lv_color_hex(0x333333));
        lv_style_set_border_opa(&style_action_btn, 255);
        lv_style_set_radius(&style_action_btn, 8);
        lv_style_set_pad_all(&style_action_btn, 0);
        lv_style_set_clip_corner(&style_action_btn, true);

        lv_style_init(&style_modal);
        lv_style_set_width(&style_modal, 494);
        lv_style_set_height(&style_modal, lv_pct(100));
        lv_style_set_layout(&style_modal, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_modal, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_cross_place(&style_modal, LV_FLEX_ALIGN_CENTER);
        lv_style_set_bg_color(&style_modal, lv_color_hex(0xffffff));
        lv_style_set_bg_opa(&style_modal, 255);
        lv_style_set_radius(&style_modal, 16);
        lv_style_set_pad_top(&style_modal, 8);
        lv_style_set_pad_bottom(&style_modal, 16);
        lv_style_set_pad_left(&style_modal, 22);
        lv_style_set_pad_right(&style_modal, 22);

        lv_style_init(&style_title_bar);
        lv_style_set_width(&style_title_bar, 375);
        lv_style_set_height(&style_title_bar, LV_SIZE_CONTENT);
        lv_style_set_min_height(&style_title_bar, 40);
        lv_style_set_layout(&style_title_bar, LV_LAYOUT_FLEX);
        lv_style_set_flex_main_place(&style_title_bar, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_title_bar, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_top(&style_title_bar, 16);
        lv_style_set_pad_bottom(&style_title_bar, 16);

        lv_style_init(&style_title);
        lv_style_set_text_align(&style_title, LV_TEXT_ALIGN_CENTER);
        lv_style_set_text_color(&style_title, lv_color_hex(0x333333));
        lv_style_set_text_font(&style_title, geist_bold_16);
        lv_style_set_text_letter_space(&style_title, 1);

        lv_style_init(&style_roller);
        lv_style_set_width(&style_roller, lv_pct(100));
        lv_style_set_height(&style_roller, lv_pct(100));
        lv_style_set_text_font(&style_roller, geist_regular_32);
        lv_style_set_text_line_space(&style_roller, 13);

        lv_style_init(&style_roller_selected);
        lv_style_set_bg_color(&style_roller_selected, lv_color_hex(0x333333));
        lv_style_set_bg_opa(&style_roller_selected, 255);
        lv_style_set_radius(&style_roller_selected, 8);
        lv_style_set_text_color(&style_roller_selected, lv_color_hex(0xffffff));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_name_static(lv_obj_0, "option_modal_#");

    lv_obj_remove_style_all(lv_obj_0);
    lv_obj_add_style(lv_obj_0, &style_backdrop, 0);
    lv_obj_t * side_left = lv_obj_create(lv_obj_0);
    lv_obj_set_name(side_left, "side_left");
    lv_obj_remove_style_all(side_left);
    lv_obj_add_style(side_left, &style_side, 0);
    lv_obj_t * cancel_btn = lv_button_create(side_left);
    lv_obj_set_name(cancel_btn, "cancel_btn");
    lv_obj_remove_style_all(cancel_btn);
    lv_obj_add_style(cancel_btn, &style_action_btn, 0);
    lv_obj_t * lv_image_0 = lv_image_create(cancel_btn);
    lv_image_set_src(lv_image_0, close);
    lv_obj_set_align(lv_image_0, LV_ALIGN_CENTER);
    lv_obj_set_width(lv_image_0, 32);
    lv_obj_set_height(lv_image_0, 32);

    lv_obj_t * modal = lv_obj_create(lv_obj_0);
    lv_obj_set_name(modal, "modal");
    lv_obj_remove_style_all(modal);
    lv_obj_add_style(modal, &style_modal, 0);
    lv_obj_t * title_bar = lv_obj_create(modal);
    lv_obj_set_name(title_bar, "title_bar");
    lv_obj_remove_style_all(title_bar);
    lv_obj_add_style(title_bar, &style_title_bar, 0);
    lv_obj_t * title_label = lv_label_create(title_bar);
    lv_obj_set_name(title_label, "title_label");
    lv_label_set_text(title_label, title);
    lv_obj_add_style(title_label, &style_title, 0);

    lv_obj_t * options_roller = lv_roller_create(modal);
    lv_obj_set_name(options_roller, "options_roller");
    lv_roller_set_options(options_roller, options, LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(options_roller, selected, false);
    lv_roller_set_visible_row_count(options_roller, 5);
    lv_obj_add_style(options_roller, &style_roller, 0);
    lv_obj_add_style(options_roller, &style_roller_selected, LV_PART_SELECTED);

    lv_obj_t * lv_obj_1 = lv_obj_create(modal);
    lv_obj_set_width(lv_obj_1, 375);
    lv_obj_set_height(lv_obj_1, 30);
    lv_obj_remove_style_all(lv_obj_1);

    lv_obj_t * side_right = lv_obj_create(lv_obj_0);
    lv_obj_set_name(side_right, "side_right");
    lv_obj_remove_style_all(side_right);
    lv_obj_add_style(side_right, &style_side, 0);
    lv_obj_t * confirm_btn = lv_button_create(side_right);
    lv_obj_set_name(confirm_btn, "confirm_btn");
    lv_obj_remove_style_all(confirm_btn);
    lv_obj_add_style(confirm_btn, &style_action_btn, 0);
    lv_obj_t * lv_image_1 = lv_image_create(confirm_btn);
    lv_image_set_src(lv_image_1, confirm);
    lv_obj_set_align(lv_image_1, LV_ALIGN_CENTER);
    lv_obj_set_width(lv_image_1, 32);
    lv_obj_set_height(lv_image_1, 32);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

