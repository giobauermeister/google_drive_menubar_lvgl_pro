/**
 * @file menubar_bg_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "menubar_bg_gen.h"
#include "gdrive_menubar.h"

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

lv_obj_t * menubar_bg_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xF0F3F8));
        lv_style_set_radius(&style_main, 0);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_shadow_color(&style_main, lv_color_hex(0x000000));
        lv_style_set_shadow_offset_y(&style_main, -2);
        lv_style_set_shadow_offset_x(&style_main, 0);
        lv_style_set_shadow_width(&style_main, 10);
        lv_style_set_shadow_opa(&style_main, (255 * 30 / 100));
        lv_style_set_pad_all(&style_main, 0);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_width(lv_obj_0, 320);
    lv_obj_set_height(lv_obj_0, 69);
    lv_obj_set_align(lv_obj_0, LV_ALIGN_BOTTOM_MID);

    lv_obj_add_style(lv_obj_0, &style_main, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "menubar_bg_#");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

