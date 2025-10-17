/**
 * @file gdrive_menubar.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "gdrive_menubar.h"

/*********************
 *      DEFINES
 *********************/
#define MAX_MENU_BUTTONS 4

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void menu_index_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
static void set_menu_buttons_icons(lv_obj_t * btn, bool selected);
static lv_observer_t * menu_idx_obs = NULL;

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * menu_buttons[MAX_MENU_BUTTONS] = {0};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void gdrive_menubar_init(const char * asset_path)
{
    gdrive_menubar_init_gen(asset_path);

    /* Add your own custom code here if needed */

#if !defined(LV_EDITOR_PREVIEW)
    lv_screen_load(screen_main_create());
#endif
}

void screen_main_loaded_cb(lv_event_t * e)
{
    lv_obj_t * screen_main = lv_event_get_target(e);

    menu_buttons[0] = lv_obj_find_by_name(screen_main, "button_home");
    menu_buttons[1] = lv_obj_find_by_name(screen_main, "button_star");
    menu_buttons[2] = lv_obj_find_by_name(screen_main, "button_shared");
    menu_buttons[3] = lv_obj_find_by_name(screen_main, "button_files");

    if (menu_idx_obs) {
        lv_observer_remove(menu_idx_obs);
        menu_idx_obs = NULL;
    }

    menu_idx_obs = lv_subject_add_observer(&subject_menu_index, menu_index_observer_cb, NULL);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void menu_index_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(observer);
    int value = lv_subject_get_int(subject);

    LV_LOG_USER("menu index changed -> %d", value);

    for (int i = 0; i < MAX_MENU_BUTTONS; ++i) set_menu_buttons_icons(menu_buttons[i], false);
    set_menu_buttons_icons(menu_buttons[value], true);
}

static void set_menu_buttons_icons(lv_obj_t * btn, bool selected)
{
    // LV_LOG_USER("set_menu_buttons_icons");
    lv_obj_t * icon_normal = lv_obj_find_by_name(btn, "icon_normal");
    lv_obj_t * icon_selected = lv_obj_find_by_name(btn, "icon_selected");
    lv_obj_t * rectangle_selected = lv_obj_find_by_name(btn, "rectangle_selected");

    if(selected) {
        lv_obj_add_flag(icon_normal, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(icon_selected, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(rectangle_selected, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_remove_flag(icon_normal, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(icon_selected, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(rectangle_selected, LV_OBJ_FLAG_HIDDEN);
    }
}
