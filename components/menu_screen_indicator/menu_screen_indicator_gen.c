/**
 * @file menu_screen_indicator_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "menu_screen_indicator_gen.h"
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

lv_obj_t * menu_screen_indicator_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_text_font(&style_main, font_inter_medium_27);
        lv_style_set_text_color(&style_main, lv_color_hex(0x43474A));

        style_inited = true;
    }

    lv_obj_t * lv_label_0 = lv_label_create(parent);
    lv_label_bind_text(lv_label_0, &subject_menu_title, NULL);

    lv_obj_add_style(lv_label_0, &style_main, 0);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_label_0, "menu_screen_indicator_#");

    return lv_label_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

