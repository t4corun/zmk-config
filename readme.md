# t4corun ZMK Config

Relearning ZMK after a long hiatus (2023). The main reason for doing this is the dongle. Setting up a XIAO Dongle setup for a GEIST Totem. 

This won't be a straight fork of [GEIGEIGEIST's](https://github.com/GEIGEIGEIST/zmk-config-totem) or [eigatech's](https://github.com/eigatech/zmk-config) repositories as I want to make it per ZMK's latest structure.

## Goals

- Minimal configuration. Leverage the documented defaults when possible
- ZMK Studio support?

## Learnings

- The totem is a composite board 
- The two outer pinky keys are part of the outer column, bottom row
- The order of includes isn't strict.

## Next

- If I want to test if Geist's will compile, remove the physical layout section in `default_layout: default_layout {` in `totem.dtsi` and see if it will build. removed `#include "totem-layouts.dtsi"` from that file

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