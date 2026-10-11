# pebble-mss
Pebble Watchface: Multifunctional Seven Segment

![](Screenshot_2015-08-11_17.00_annotation.png?raw=true)

This project is based on "Multifunctional 7 Segment" by [cfg1](https://github.com/cfg1).
Original copyright (c) 2017 [cfg1](https://github.com/cfg1).
Licensed under GPL-3.0.

This repository:
Modifications copyright (c) 2026
Also licensed under GPL-3.0.

-----
Version: 1.2.1
Published: 11/10/2026
Release Notes:
* Fixed crash which prevented users from using the watchface at all. Related to new moon handling, a new health event type, and a recent Pebble App update

-----
Version: 1.2.0
Published: 6/24/2026
Release Notes:
* Feature: Customize the space to the right below the time - Switch between showing Calendar Week, Heart Rate or nothing. Options available on new settings item: Right side below clock
* Calendar week is now possible to be shown on the date line above the clock instead of year. New options available in the Date Format selector on the settings page 
* Pebble Time 2: Enlarged steps/sleep and Calendar Week / Heart rate font size
* Pebble Time 2: "Rounded" corners of clock digits a bit

Notice: Heart rate on the watchface is following the Pebble Health Heart rate update interval.

Notice: The bug with the up/down arrow on steps should be fixed now. It is not related to this watchface but rather a bug in the pebble phone app, which has been fixed. There might still be an issue with sleep, but i believe this is fixed soon.

-----
Version: 1.1.3
Published: 5/31/2026
Release Notes:
* Fixed pkjs issue that would crash settings from the settings page to carry over to the watch if using an original Pebble or Pebble Steel

Notice: There is still an issue with the up/down arrow of sleep/steps. It might be related to a bug in the current new pebble app, since it works in the old app. It has been reported through their new app and to their github issue page.

-----
Version: 1.1.1
Published: 5/30/2026
Release Notes:
* Fixed various graphic glitches when switching between old themes and custom theme

Notice: There is still an issue with the up/down arrow of sleep/steps. It might be related to a bug in the current new pebble app. I'm testing some things out that I'm done with yet, but decided that since it dosn't work currently, i might as well release this now

-----
Version: 1.1.0
Published: 5/16/2026
Release Notes:
* Fix for watchface getting messed up when Timeline Peek gets triggered on Pebble Time 2
* Moved digits on Pebble Time 2, to be further away from edge of screen
* Added new handling of step/sleep icon, so that it matches the color of the sub clock text
* (Possible) Fix for up/down arrow in health always pointing down

Notice: There is still an issue with the up/down arrow of sleep/steps. It might be related to a bug in the current new pebble app. I'm testing some things out that I'm done with yet, but decided that since it dosn't work currently, i might as well release this now
