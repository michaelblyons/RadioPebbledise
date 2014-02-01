#include "pebble.h"

/*
 * This is ultimately intended to be a full-featured control
 * for RadioParadise's Android app.
 * https://play.google.com/store/apps/details?id=com.earthflare.anddroid.radioparadisewidget&hl=en
 * 
 * Its development is not currently sanctioned by RP.
 *
 */

char *ratings[] = {
    "- None -",
    "10 - Godlike",
    "9 - Outstanding",
    "8 - Most Excellent",
    "7 - Quite Likeable",
    "6 - Pretty Good",
    "5 - Decent",
    "4 - Acceptable",
    "3 - Ho Hum",
    "2 - Marginal",
    "1 - Sucko-barfo"
};
#define NUM_RATINGS sizeof(ratings) / sizeof(char*)

bool IS_PSD = false;
bool IS_PLAYING = false;

/*
 * Global and static UI elements.
 *
 * This app uses two windows:
 * - the main_window
 * - the rating_window, which uses a menu_layer to rate a song
 *
 */

static Window *main_window;
static Window *rating_window;
static ActionBarLayer *main_action_bar;

static GBitmap *icon_ctrl_play;
static GBitmap *icon_ctrl_stop;
static GBitmap *icon_ctrl_psd;
static GBitmap *icon_ctrl_return;
static BitmapLayer *current_status_layer;

/*
 * Event handlers
 */
void play_pause_click_handler(ClickRecognizerRef recognizer, void *context){
    IS_PLAYING = !IS_PLAYING;

    if(IS_PLAYING){
        action_bar_layer_set_icon(main_action_bar, BUTTON_ID_SELECT, icon_ctrl_stop);
        bitmap_layer_set_bitmap(current_status_layer, icon_ctrl_play);
    }
    else{
        action_bar_layer_set_icon(main_action_bar, BUTTON_ID_SELECT, icon_ctrl_play);
        bitmap_layer_set_bitmap(current_status_layer, icon_ctrl_stop);
    }
}

void main_config_provider(void *context){
    window_single_click_subscribe(BUTTON_ID_SELECT, play_pause_click_handler);
}

/*
 * Standard practice functions
 */
static void init() {
    main_window = window_create();
    window_stack_push(main_window, true /* Animated */);

    main_action_bar = action_bar_layer_create();
    action_bar_layer_add_to_window(main_action_bar, main_window);
    action_bar_layer_set_click_config_provider(main_action_bar, main_config_provider);

    icon_ctrl_play = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_CTRL_PLAY);
    icon_ctrl_stop = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_CTRL_STOP);
    icon_ctrl_psd = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_CTRL_PSD);
    icon_ctrl_return = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_CTRL_RETURN);

    action_bar_layer_set_icon(main_action_bar, BUTTON_ID_UP, icon_ctrl_return);
    action_bar_layer_set_icon(main_action_bar, BUTTON_ID_DOWN, icon_ctrl_psd);
    action_bar_layer_set_icon(main_action_bar, BUTTON_ID_SELECT, icon_ctrl_play);

    Layer* window_layer = window_get_root_layer(main_window);
    GRect bounds = layer_get_frame(window_layer);
    current_status_layer = bitmap_layer_create(bounds);
    bitmap_layer_set_bitmap(current_status_layer, icon_ctrl_return);
    layer_add_child(window_layer, bitmap_layer_get_layer(current_status_layer));
}

static void deinit() {
    gbitmap_destroy(icon_ctrl_play);
    gbitmap_destroy(icon_ctrl_stop);
    gbitmap_destroy(icon_ctrl_psd);
    gbitmap_destroy(icon_ctrl_return);
    bitmap_layer_destroy(current_status_layer);
    window_destroy(main_window);
}

int main(void) {
    init();
    app_event_loop();
    deinit();
}
