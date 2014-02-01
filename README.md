RadioPebbledise
===============

This is ultimately intended to be a full-featured [Pebble][pebble] watch control for [RadioParadise][rp]'s [Android app][rp_android].

Its development is not currently sanctioned, but I'm hoping things work out.

Development Notes
=================

Don't laugh. This is my first time with Pebble or with straight-up C. The below is bound to change as I learn how to do things.

(Intended) Structure
--------------------

+ __Window__ Main (Now Playing) screen
    + __ActionBarLayer__ Controls
        1. Return to Stream (if PSD)
           + If not PSD, rate song?
           + Long Press to rate song when PSD?
        2. Play/Stop
        3. PSD
    + __Layer__ Song info
        + __TextLayer__ Song name
        + __TextLayer__ Band name
+ __Window__? Ratings screen
    + __TextLayer__? Song name?
    + __MenuLayer__ Ratings
        + It'll be interesting to try to load current ratings and hide the "None" option if a song rating already exists.

Possible Future Features
------------------------

+ __Window__ Startup screen
    + __ImageLayer__ Layer
        + __Image__ RP Logo
+ __Window__ Lyrics screen
    + __ScrollLayer__ Lyrics container

[pebble]: http://getpebble.com "Official Pebble Website"
[rp]: http://radioparadise.com
[rp_android]: https://play.google.com/store/apps/details?id=com.earthflare.anddroid.radioparadisewidget&hl=en "Official Pebble Android app"
