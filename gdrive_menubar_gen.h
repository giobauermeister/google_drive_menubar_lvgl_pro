/**
 * @file gdrive_menubar_gen.h
 */

#ifndef GDRIVE_MENUBAR_GEN_H
#define GDRIVE_MENUBAR_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * font_inter_medium_14;

extern lv_font_t * font_inter_medium_27;

/*----------------
 * Images
 *----------------*/

extern const void * img_house_selected;
extern const void * img_star_selected;
extern const void * img_person_selected;
extern const void * img_file_selected;
extern const void * img_house;
extern const void * img_star;
extern const void * img_person;
extern const void * img_file;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_menu_index;
extern lv_subject_t subject_menu_title;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void screen_main_loaded_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void gdrive_menubar_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "components/menu_button/menu_button_gen.h"
#include "components/menu_screen_indicator/menu_screen_indicator_gen.h"
#include "components/menubar_bg/menubar_bg_gen.h"
#include "screens/screen_main/screen_main_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*GDRIVE_MENUBAR_GEN_H*/