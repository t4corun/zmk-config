/*
 * Best Practice: Define reusable constants and macros
 */

#pragma once

#include "helper_macros.h"

// put the default base layers first
#define _QWERTY        0
#define _GRAPHITE      1
#define _NAVIGATION    2
#define _NUMBER        3
#define _SYMBOL        4
#define _FUNCTION      5

#define _BASELAYERS _QWERTY _GRAPHITE

// Behavior Configuration
#define TAPPING_TERM         220
#define QUICK_TAP_TERM       150
#define PRIOR_IDLE_TERM      125

#define HRM_TAPPING_TERM     (TAPPING_TERM + 100)

#define COMBO_TIMEOUT        50

// homerow mods
#define HRML(k1, k2, k3, k4) &hrmgui  LGUI k1   &hrmlalt LALT k2   &hrmleft LCTRL k3  &hrmleft LSHFT k4
#define HRMR(k1, k2, k3, k4) &hrmrght RSHFT k1  &hrmrght RCTRL k2  &hrmralt RALT k3   &hrmgui  RGUI  k4

// layer changes
#define NUMBER               &mo  _NUMBER
#define NAVIGATION           &mo  _NAVIGATION
#define FUNCTION             &mo  _FUNCTION

#define QWERTY               &to  _QWERTY
#define GRAPHITE             &to  _GRAPHITE

#define NUMBLOCK             &tog _NUMBER
#define NAVILOCK             &tog _NAVIGATION

// other shortcuts
#define VOL_UP               &kp C_VOL_UP
#define VOL_DOWN             &kp C_VOL_DN
#define VOL_MUTE             &kp C_MUTE

// windows shortcuts
#define W_SNIP               &kp LG(LS(S))

// wireless connectivity and output modes. Cycles through profiles 1-6
#define BT_CLEAR             &bt BT_CLR
#define BT_NEXT              &bt BT_NXT
#define BT_PREV              &bt BT_PRV
#define OUTPUT_TOG           &out OUT_TOG

// keymap macros
#define __________                                             &trans
#define ____xx____                                             &none
#define _BASE_L4________________________                       &mkp MB1   NUMBER     &sk LSHFT
#define _BASE_R4________________________                       &kp SPACE  NAVIGATION &kp BSPC
#define _LAYER_TRANS____________________                       ____xx____ __________ ____xx____
#define _MODS_GACS_________________________________            &kp LGUI   &kp LALT   &kp LCTRL  &kp LSHFT
#define _MODS_SCAG_________________________________            &kp RSHFT  &kp RCTRL  &kp RALT   &kp RGUI
#define _SHORTCUTS_UCCPR______________________________________ &kp LC(Z)  &kp LC(X)  &kp LC(C)  &kp LC(V)  &kp LC(Y)
#define _NONE_5_______________________________________________ ____xx____ ____xx____ ____xx____ ____xx____ ____xx____

// The 0 is required because we are hard coding the macro but the behavior
// still wants two parameters
#define MACRO_BRC  &ht_brc 0 LBRC
#define MACRO_LGT  &ht_lgt 0 LT
#define MACRO_BKT  &ht_bkt 0 LBKT
#define MACRO_PAR  &ht_par 0 LPAR
#define MACRO_SQUO &ht_sqt 0 SQT
#define MACRO_DQUO &ht_dqt 0 DQT
