#pragma once

// put the default base layers first
#define _QWERTY     0
#define _NUMBER     1
#define _NAVIGATION 2

//                           xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx|xxxxxxxxxxxxxxx 
#define HRML(k1, k2, k3, k4) &mt LGUI k1     &mt LALT k2     &mt LCTRL k3    &mt LSHFT k4
#define HRMR(k1, k2, k3, k4) &mt RSHFT k1    &mt RCTRL k2    &mt RALT k3     &mt RGUI  k4

// layer changes
#define NUM                  &lt _NUMBER
#define NAV                  &lt _NAVIGATION

//Behavior Configuration
#define TAPPING_TERM 200
