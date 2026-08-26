# t4corun ZMK Config

Relearning ZMK after a long hiatus (2023) because of the dongle. Setting up a XIAO Dongle setup for a GEIST Totem. 

This won't be a straight fork of [GEIGEIGEIST's](https://github.com/GEIGEIGEIST/zmk-config-totem) or [eigatech's](https://github.com/eigatech/zmk-config) repositories as I want to make it per 
ZMK's latest structure.

## Goals

- Minimal configuration. Leverage the documented defaults when possible
- ZMK Studio support?

## Learnings

- `boards` are now under zmk-config root instead of inside `/config/`. Why?
- The totem is a composite board 
- The two outer pinky keys are part of the outer column, bottom row

## Next

- Go over totem.dtsi, it seems like I need to create a separate totem-layouts.dtsi if I want to be able to use zmk studio
- If I want to test if Geist's will compile, remove the physical layout section in `default_layout: default_layout {` in `totem.dtsi` and see if it will build
- I can have t4corun.conf to have global settings but I don't know if I need it

### Files that are blank that could be added back

config/t4corun.conf
boards/shields/totem/totem_left.conf
boards/shields/totem/totem_right.conf