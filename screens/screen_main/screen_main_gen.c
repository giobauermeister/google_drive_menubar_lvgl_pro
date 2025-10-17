/**
 * @file screen_main_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_main_gen.h"
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

lv_obj_t * screen_main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_menu_items;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_menu_items);
        lv_style_set_bg_opa(&style_menu_items, 0);
        lv_style_set_border_width(&style_menu_items, 0);
        lv_style_set_radius(&style_menu_items, 0);
        lv_style_set_pad_all(&style_menu_items, 0);
        lv_style_set_layout(&style_menu_items, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_menu_items, LV_FLEX_FLOW_ROW);

        style_inited = true;
    }

    lv_obj_t * screen_main = lv_obj_create(NULL);
    lv_obj_set_name(screen_main, "screen_main");
    lv_obj_set_style_bg_color(screen_main, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t * menu_screen_indicator_0 = menu_screen_indicator_create(screen_main);
    lv_obj_set_align(menu_screen_indicator_0, LV_ALIGN_TOP_MID);
    lv_obj_set_y(menu_screen_indicator_0, 35);
    
    lv_obj_t * menubar_bg_0 = menubar_bg_create(screen_main);
    lv_obj_set_align(menubar_bg_0, LV_ALIGN_BOTTOM_MID);
    lv_obj_t * lv_obj_0 = lv_obj_create(menubar_bg_0);
    lv_obj_set_width(lv_obj_0, LV_SIZE_CONTENT);
    lv_obj_set_height(lv_obj_0, LV_SIZE_CONTENT);
    lv_obj_set_align(lv_obj_0, LV_ALIGN_CENTER);
    lv_obj_add_style(lv_obj_0, &style_menu_items, 0);
    lv_obj_t * button_home = menu_button_create(lv_obj_0, "Home", img_house, img_house_selected);
    lv_obj_set_name(button_home, "button_home");
    lv_obj_add_subject_set_int_event(button_home, &subject_menu_index, LV_EVENT_CLICKED, 0);
    lv_obj_add_subject_set_string_event(button_home, &subject_menu_title, LV_EVENT_CLICKED, "Home");
    
    lv_obj_t * button_star = menu_button_create(lv_obj_0, "Starred", img_star, img_star_selected);
    lv_obj_set_name(button_star, "button_star");
    lv_obj_add_subject_set_int_event(button_star, &subject_menu_index, LV_EVENT_CLICKED, 1);
    lv_obj_add_subject_set_string_event(button_star, &subject_menu_title, LV_EVENT_CLICKED, "Starred");
    
    lv_obj_t * button_shared = menu_button_create(lv_obj_0, "Shared", img_person, img_person_selected);
    lv_obj_set_name(button_shared, "button_shared");
    lv_obj_add_subject_set_int_event(button_shared, &subject_menu_index, LV_EVENT_CLICKED, 2);
    lv_obj_add_subject_set_string_event(button_shared, &subject_menu_title, LV_EVENT_CLICKED, "Shared");
    
    lv_obj_t * button_files = menu_button_create(lv_obj_0, "Files", img_file, img_file_selected);
    lv_obj_set_name(button_files, "button_files");
    lv_obj_add_subject_set_int_event(button_files, &subject_menu_index, LV_EVENT_CLICKED, 3);
    lv_obj_add_subject_set_string_event(button_files, &subject_menu_title, LV_EVENT_CLICKED, "Files");
    
    lv_obj_add_event_cb(screen_main, screen_main_loaded_cb, LV_EVENT_SCREEN_LOADED, NULL);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name_static(screen_main, "screen_main");

    return screen_main;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

