/*
 * Best Practice: Define reusable constants and macros
 */

#pragma once

#include "helper_macros.h"

// put the default base layers first
#define _QWERTY        0
#define _GRAPHITE      1
#define _GAME          2
#define _GAMENUM       3
#define _NAVIGATION    4
#define _NUMBER        5
#define _SYMBOL        6
#define _FUNCTION      7

#define _BASELAYERS _QWERTY _GRAPHITE _GAME

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
#define GAMENUM              &mo  _GAMENUM

#define QWERTY               &to  _QWERTY
#define GRAPHITE             &to  _GRAPHITE
#define GAME                 &to  _GAME

#define NUMLOCK              &tog _NUMBER
#define NAVLOCK              &tog _NAVIGATION

// other shortcuts
#define VOL_UP               &kp C_VOL_UP
#define VOL_DOWN             &kp C_VOL_DN
#define VOL_MUTE             &kp C_MUTE

// windows shortcuts
#define W_SNIP               &kp LG(LS(S))

// wireless connectivity and output modes. Cycles through profiles 1-6
#define BT_CLEAR             &bt BT_CLR
#define BT_0                 &bt BT_SEL 0
#define BT_1                 &bt BT_SEL 1
#define BT_2                 &bt BT_SEL 2
#define BT_3                 &bt BT_SEL 3
#define BT_4                 &bt BT_SEL 4
#define BT_5                 &bt BT_SEL 5
#define OUTPUT_TOG           &out OUT_TOG

// hold tap macros
// The 0 is required because we are hard coding the macro but the behavior
// still wants two parameters
#define MACRO_BRC            &ht_brc 0 LBRC
#define MACRO_LGT            &ht_lgt 0 LT
#define MACRO_BKT            &ht_bkt 0 LBKT
#define MACRO_PAR            &ht_par 0 LPAR
#define MACRO_SQUO           &ht_sqt 0 SQT
#define MACRO_DQUO           &ht_dqt 0 DQT

// keymap macros
#define __________                                             &trans
#define ____xx____                                             &none
#define BASE_L4_________________________                       &mkp MB1   NUMBER     &sk LSHFT
#define BASE_R4_________________________                       &kp SPACE  NAVIGATION &kp BSPC
#define LAYER_TRANS_____________________                       ____xx____ __________ ____xx____
#define MODS_GACS__________________________________            &kp LGUI   &kp LALT   &kp LCTRL  &kp LSHFT
#define MODS_SCAG__________________________________            &kp RSHFT  &kp RCTRL  &kp RALT   &kp RGUI
#define SHORTCUTS_UCCPR_______________________________________ &kp LC(Z)  &kp LC(X)  &kp LC(C)  &kp LC(V)  &kp LC(Y)
#define NONE_5________________________________________________ ____xx____ ____xx____ ____xx____ ____xx____ ____xx____
