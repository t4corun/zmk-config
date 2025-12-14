# t4corun ZMK Config

Relearning ZMK after a long hiatus (2023), primarily for the dongle. Setting up a XIAO Dongle setup for a GEIST Totem and porting over my QMK keymap

This won't be a straight fork of [GEIGEIGEIST's](https://github.com/GEIGEIGEIST/zmk-config-totem) or [eigatech's](https://github.com/eigatech/zmk-config) repositories as I want to make it per ZMK's latest structure.

## Features

My keymap is designed with SQL and Powershell in mind. It features:

- Dongle support
- Minimal configuration. Leverage the documented defaults when possible
- Timerless homerow mods
- Macros for bracket symbols

## Learnings

- The totem is a composite board 
- The two outer pinky keys are part of the outer column, bottom row
- The order of includes isn't strict.

## Next

- Add alternate base layer for gallium, graphite, or colemak dh

### Files that were removed because they were blank

These could be added back

- config/t4corun.conf
- boards/shields/totem/totem_left.conf
- boards/shields/totem/totem_right.conf

### Special Thanks

geigeigeist, for making a beautiful, well documented keyboard, and making it free
eigatech, for sharing the dongle code
rafaelromao, for the macro helpers
urob, for the timerless setup
caksoylar, for the general organization and rgbled widget