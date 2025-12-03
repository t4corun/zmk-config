#pragma once

// put the default base layers first
#define _QWERTY     0
#define _NUMBER     1
#define _NAVIGATION 2


// layer changes
#define NUM                  &mo _NUMBER
#define NAV                  &mo _NAVIGATION

//Behavior Configuration
#define TAPPING_TERM 200

//                           xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx 
#define HRML(k1, k2, k3, k4) &mt LGUI k1     &mt LALT k2     &mt LCTRL k3    &mt LSHFT k4
#define HRMR(k1, k2, k3, k4) &mt RSHFT k1    &mt RCTRL k2    &mt RALT k3     &mt RGUI  k4

//                                 xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx
#define _BASE_L4_________________  &kp TAB     NUM     &kp LSHFT
#define _BASE_R4_________________  &kp SPACE   NAV     &kp BSPC
