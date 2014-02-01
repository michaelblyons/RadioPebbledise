RadioPebbledise
===============

This is ultimately intended to be a full-featured [Pebble](http://getpebble.com) watch control for [RadioParadise](http://radioparadise.com)'s [Android app](https://play.google.com/store/apps/details?id=com.earthflare.anddroid.radioparadisewidget&hl=en).

Its development is not currently sanctioned, but I'm hoping things work out.

Development Notes
=================

Don't laugh. This is my first time with Pebble or with straight-up C. The below is bound to change as I learn how to do things.

(Intended) Structure
--------------------

+ *Window* Startup screen
    + *Layer* Layer
        + *Image* RP Logo
+ *Window* Main (Now Playing) screen
    + *Layer* Controls
        + *Image* Sprites
    + *Layer* Song info
        + *Text* Song name
        + *Text* Band name
+ *Window*? Ratings screen
    + *MenuLayer* Ratings