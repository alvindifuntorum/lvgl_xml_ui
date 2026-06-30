/**
 * @file climate_gen.h
 */

#ifndef CLIMATE_H
#define CLIMATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#include "lvgl_private.h"
#else
#include "lvgl/lvgl.h"
#include "lvgl/lvgl_private.h"
#endif

#ifdef LV_USE_XML
#include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t *climate_create(lv_obj_t *parent);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*CLIMATE_H*/
