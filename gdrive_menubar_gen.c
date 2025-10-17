/**
 * @file gdrive_menubar_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "gdrive_menubar_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_inter_medium_14;
extern lv_font_t font_inter_medium_14_data;
lv_font_t * font_inter_medium_27;
extern lv_font_t font_inter_medium_27_data;

/*----------------
 * Images
 *----------------*/

const void * img_house_selected;
extern const void * img_house_selected_data;
const void * img_star_selected;
extern const void * img_star_selected_data;
const void * img_person_selected;
extern const void * img_person_selected_data;
const void * img_file_selected;
extern const void * img_file_selected_data;
const void * img_house;
extern const void * img_house_data;
const void * img_star;
extern const void * img_star_data;
const void * img_person;
extern const void * img_person_data;
const void * img_file;
extern const void * img_file_data;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_menu_index;
lv_subject_t subject_menu_title;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void gdrive_menubar_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/

    /* get font 'font_inter_medium_14' from a C array */
    font_inter_medium_14 = &font_inter_medium_14_data;
    /* get font 'font_inter_medium_27' from a C array */
    font_inter_medium_27 = &font_inter_medium_27_data;


    /*----------------
     * Images
     *----------------*/
    img_house_selected = &img_house_selected_data;
    img_star_selected = &img_star_selected_data;
    img_person_selected = &img_person_selected_data;
    img_file_selected = &img_file_selected_data;
    img_house = &img_house_data;
    img_star = &img_star_data;
    img_person = &img_person_data;
    img_file = &img_file_data;

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_menu_index, 0);
    lv_subject_set_min_value_int(&subject_menu_index, 0);
    lv_subject_set_max_value_int(&subject_menu_index, 4);
    static char subject_menu_title_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_menu_title_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_menu_title,
                           subject_menu_title_buf,
                           subject_menu_title_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Home"
                          );

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */
    lv_xml_register_font(NULL, "font_inter_medium_14", font_inter_medium_14);
    lv_xml_register_font(NULL, "font_inter_medium_27", font_inter_medium_27);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_menu_index", &subject_menu_index);
    lv_xml_register_subject(NULL, "subject_menu_title", &subject_menu_title);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "screen_main_loaded_cb", screen_main_loaded_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_house_selected", img_house_selected);
    lv_xml_register_image(NULL, "img_star_selected", img_star_selected);
    lv_xml_register_image(NULL, "img_person_selected", img_person_selected);
    lv_xml_register_image(NULL, "img_file_selected", img_file_selected);
    lv_xml_register_image(NULL, "img_house", img_house);
    lv_xml_register_image(NULL, "img_star", img_star);
    lv_xml_register_image(NULL, "img_person", img_person);
    lv_xml_register_image(NULL, "img_file", img_file);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) screen_main_loaded_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("screen_main_loaded_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/