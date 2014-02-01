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

/*
 * Global and static UI elements.
 *
 * This app uses two windows:
 * - the main_window
 * - the rating_window, which uses a menu_layer to rate a song
 *
 */

static Window *main_window;

static GBitmap *image;
static BitmapLayer *image_layer;


static void init() {
  main_window = window_create();
  window_stack_push(main_window, true /* Animated */);

  image = gbitmap_create_with_resource(IMAGE_NO_LITTER);

  Layer* window_layer = window_get_root_layer(main_window);
  GRect bounds = layer_get_frame(window_layer);
  image_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(image_layer, image);
  layer_add_child(window_layer, bitmap_layer_get_layer(image_layer));
}

static void deinit() {
  gbitmap_destroy(image);
  bitmap_layer_destroy(image_layer);
  window_destroy(main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
