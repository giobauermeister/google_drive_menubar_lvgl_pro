/**
 * @file menu_button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "menu_button_gen.h"
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

static lv_anim_timeline_t * timeline_menu_item_selected_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * menu_button_create(lv_obj_t * parent, const char * text, const void * image, const void * image_selected)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_selected;
    static lv_style_t style_icon_container;
    static lv_style_t style_click_area;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_opa(&style_main, 0);
        lv_style_set_radius(&style_main, 0);
        lv_style_set_border_width(&style_main, 0);
        lv_style_set_pad_all(&style_main, 0);

        lv_style_init(&style_selected);
        lv_style_set_bg_color(&style_selected, lv_color_hex(0xC3E7FF));
        lv_style_set_radius(&style_selected, 100);
        lv_style_set_border_width(&style_selected, 0);
        lv_style_set_pad_all(&style_selected, 0);

        lv_style_init(&style_icon_container);
        lv_style_set_bg_opa(&style_icon_container, 0);
        lv_style_set_pad_all(&style_icon_container, 0);
        lv_style_set_border_width(&style_icon_container, 0);

        lv_style_init(&style_click_area);
        lv_style_set_bg_opa(&style_click_area, 0);
        lv_style_set_border_width(&style_click_area, 0);
        lv_style_set_pad_all(&style_click_area, 0);

        style_inited = true;
    }

    lv_obj_t * menu_button = lv_obj_create(parent);
    lv_obj_set_name(menu_button, "menu_button");
    lv_obj_set_width(menu_button, 70);
    lv_obj_set_height(menu_button, 49);
    lv_obj_set_flag(menu_button, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_flag(menu_button, LV_OBJ_FLAG_CLICKABLE, true);


    // create animation timeline(s)
    lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _MENU_BUTTON_TIMELINE_CNT);
    at_array[MENU_BUTTON_TIMELINE_MENU_ITEM_SELECTED] = timeline_menu_item_selected_create(menu_button);
    lv_obj_set_user_data(menu_button, at_array);
    lv_obj_add_event_cb(menu_button, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

    lv_obj_add_style(menu_button, &style_main, 0);
    lv_obj_t * rectangle_selected = lv_obj_create(menu_button);
    lv_obj_set_name(rectangle_selected, "rectangle_selected");
    lv_obj_set_width(rectangle_selected, 70);
    lv_obj_set_height(rectangle_selected, 35);
    lv_obj_set_flag(rectangle_selected, LV_OBJ_FLAG_SCROLLABLE, false);
    lv_obj_set_align(rectangle_selected, LV_ALIGN_TOP_MID);
    lv_obj_set_flag(rectangle_selected, LV_OBJ_FLAG_HIDDEN, false);
    lv_obj_set_flag(rectangle_selected, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_set_flag(rectangle_selected, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_add_style(rectangle_selected, &style_selected, 0);
    
    lv_obj_t * icon_container = lv_obj_create(menu_button);
    lv_obj_set_name(icon_container, "icon_container");
    lv_obj_set_width(icon_container, 30);
    lv_obj_set_height(icon_container, 30);
    lv_obj_set_align(icon_container, LV_ALIGN_TOP_MID);
    lv_obj_set_y(icon_container, 3);
    lv_obj_set_flag(icon_container, LV_OBJ_FLAG_EVENT_BUBBLE, true);
    lv_obj_add_style(icon_container, &style_icon_container, 0);
    lv_obj_t * icon_normal = lv_image_create(icon_container);
    lv_obj_set_name(icon_normal, "icon_normal");
    lv_image_set_src(icon_normal, image);
    lv_obj_set_align(icon_normal, LV_ALIGN_CENTER);
    
    lv_obj_t * icon_selected = lv_image_create(icon_container);
    lv_obj_set_name(icon_selected, "icon_selected");
    lv_image_set_src(icon_selected, image_selected);
    lv_obj_set_align(icon_selected, LV_ALIGN_CENTER);
    lv_obj_set_flag(icon_selected, LV_OBJ_FLAG_HIDDEN, true);
    
    lv_obj_t * menu_title = lv_label_create(menu_button);
    lv_obj_set_name(menu_title, "menu_title");
    lv_label_set_text(menu_title, text);
    lv_obj_set_y(menu_title, 3);
    lv_obj_set_align(menu_title, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_text_font(menu_title, font_inter_medium_14, 0);
    lv_obj_set_style_text_color(menu_title, lv_color_hex(0x43474A), 0);
    
    lv_obj_add_play_timeline_event(menu_button, LV_EVENT_CLICKED, menu_button_get_timeline(menu_button, MENU_BUTTON_TIMELINE_MENU_ITEM_SELECTED), 0, false);

    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(menu_button, "menu_button_#");

    return menu_button;
}

lv_anim_timeline_t * menu_button_get_timeline(lv_obj_t * obj, menu_button_timeline_t timeline_id)
{
    if (timeline_id >= _MENU_BUTTON_TIMELINE_CNT) {
        LV_LOG_WARN("menu_button has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_menu_item_selected_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_WIDTH & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, "rectangle_selected");
    lv_anim_set_values(&a, 0, 70);
    lv_anim_set_duration(&a, 100);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, "rectangle_selected");
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 50);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _MENU_BUTTON_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

