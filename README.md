RadioPebbledise
===============

This is ultimately intended to be a full-featured [Pebble][pebble] watch control for [RadioParadise][rp]'s [Android app][rp_android].

Its development is not currently sanctioned, but I'm hoping things work out.

Development Notes
=================

Don't laugh. This is my first time with Pebble or with straight-up C. The below is bound to change as I learn how to do things.

(Intended) Structure
--------------------

+ __Window__ Startup screen
    + __Layer__ Layer
        + __Image__ RP Logo
+ __Window__ Main (Now Playing) screen
    + __Layer__ Controls
        + __Image__ Sprites
    + __Layer__ Song info
        + __Text__ Song name
        + __Text__ Band name
+ __Window__? Ratings screen
    + __MenuLayer__ Ratings

[pebble]: http://getpebble.com "Official Pebble Website"
[rp]: http://radioparadise.com
[rp_android]: https://play.google.com/store/apps/details?id=com.earthflare.anddroid.radioparadisewidget&hl=en "Official Pebble Android app"
