#pragma once

// put the default base layers first
enum layers {
    _QWERTY = 0,
    DEFAULT_LAYER = 0,
    _COLEMAK_DH,
    _GAME,
    _NAVIGATION,
    _NUMBER,
    _SYMBOL,
    _FUNCTION
};

//                           xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx 
#define HRML(k1, k2, k3, k4) &hm LGUI k1     &hm LALT k2     &hm LCTRL k3    &hm LSHFT k4
#define HRMR(k1, k2, k3, k4) &hm RSHFT k1    &hm RCTRL k2    &hm RALT k3     &hm RGUI  k4

// layer changes
#define NUM                  &mt _NUMBER
#define NAV                  &mt _NAVIGATION

//Behavior Configuration
#define TAPPING_TERM 200
