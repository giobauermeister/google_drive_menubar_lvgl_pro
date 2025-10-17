/**
 * @file menu_button_gen.h
 */

#ifndef MENU_BUTTON_H
#define MENU_BUTTON_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    MENU_BUTTON_TIMELINE_MENU_ITEM_SELECTED = 0,
    _MENU_BUTTON_TIMELINE_CNT = 1
}menu_button_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * menu_button_create(lv_obj_t * parent, const char * text, const void * image, const void * image_selected);

/**
 * Get a timeline of a menu_button
 * @param obj          pointer to a menu_button component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * menu_button_get_timeline(lv_obj_t * obj, menu_button_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*MENU_BUTTON_H*/