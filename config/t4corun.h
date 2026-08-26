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
#define TAPPING_TERM         190
#define QUICK_TAP_TERM       150
#define PRIOR_IDLE_TERM      150

#define HRM_TAPPING_TERM     (TAPPING_TERM + 100)

#define COMBO_TIMEOUT        50

// homerow mods
#define HRML(k1, k2, k3, k4) &hrmgui  LGUI  k1, &hrmlalt LALT  k2, &hrmleft LCTRL k3, &hrmleft LSHFT k4
#define HRMR(k1, k2, k3, k4) &hrmrght RSHFT k1, &hrmrght RCTRL k2, &hrmralt RALT  k3, &hrmgui  RGUI  k4

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

// encoder shortcuts
#define ENC_NONE             &inc_dec_kp &none         &none
#define ENC_VOL              &inc_dec_kp C_VOL_UP      C_VOL_DN

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
//                                                                 xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx
#define __________                                                 &trans
#define ____xx____                                                 &none
#define __NONE_4__                                                 ____xx____, ____xx____, ____xx____, ____xx____
#define BASE_L4___________________________                         &mkp MB1,   NUMBER,     &kp LSHFT
#define BASE_R4___________________________                         &kp SPACE,  NAVIGATION, &key_repeat
#define LAYER_TRANS_______________________                         ____xx____, __________, ____xx____
#define MODS_GACS_____________________________________             &kp LGUI,   &kp LALT,   &kp LCTRL,  &kp LSHFT
#define MODS_SCAG_____________________________________             &kp RSHFT,  &kp RCTRL,  &kp RALT,   &kp RGUI
#define SHORTCUTS_UCCPR___________________________________________ &kp LC(Z),  &kp LC(X),  &kp LC(C),  &kp LC(V),  &kp LC(Y)
#define NONE_5____________________________________________________ ____xx____, ____xx____, ____xx____, ____xx____, ____xx____


// layer definition macros
// Represents the base 3x5 with 3 thumb keys on each side
// The keybaord specific keys are managed in the keyboard's keymap file
#define LAYER_QWERTY                                                                                                            \
    &kp Q,      &kp W,      &kp E,      &kp R,      &kp T,          &kp Y,      &kp U,      &kp I,      &kp O,      &kp P,      \
    HRML(A,     S,          D,          F),         &kp G,          &kp H,      HRMR(J,     K,          L,          SQT),       \
    &kp Z,      &kp X,      &kp C,      &kp V,      &kp B,          &kp N,      &kp M,      &ko_com,    &ko_dot,    &kp MINUS,  \
                            BASE_L4___________________________,     BASE_R4___________________________



#define LAYER_GRAPHITE                                                                                                          \
    &kp B,      &kp L,      &kp D,      &kp W,      &kp Z,          &kp SQT,    &kp F,      &kp O,      &kp U,      &kp J,      \
    HRML(N,     R,          T,          S),         &kp G,          &kp Y,      HRMR(H,     A,          E,          I),         \
    &kp Q,      &kp X,      &kp M,      &kp C,      &kp V,          &kp K,      &kp P,      &ko_gdot,   &kp MINUS,  &ko_gcom,   \
                            BASE_L4___________________________,     BASE_R4___________________________



#define LAYER_GAME                                                                                                              \
    &kp TAB,    &kp Q,      &kp W,      &kp E,      &kp R,          NONE_5____________________________________________________, \
    &kp LCTRL,  &kp A,      &kp S,      &kp D,      &kp F,          NONE_5____________________________________________________, \
    &kp Z,      &kp X,      &kp C,      &kp V,      &kp B,          &kp ENTER,  ____xx____, VOL_DOWN,   VOL_UP,     VOL_MUTE,   \
                            GAMENUM,    &kp SPACE,  &kp LSHFT,      BASE_R4___________________________


#define LAYER_GAMENUM                                                                                                           \
    &kp N8,     &kp N7,     &kp N6,     &kp N5,     &kp T,          NONE_5____________________________________________________, \
    &kp N4,     &kp N3,     &kp N2,     &kp N1,     &kp G,          NONE_5____________________________________________________, \
    &kp GRAVE,  &kp ESC,    ____xx____, &kp ENTER,  &kp LALT,       NONE_5____________________________________________________, \
                            __________, ____xx____, ____xx____,     QWERTY,     GRAPHITE,  ____xx____


#define LAYER_NAVIGATION                                                                                                        \
    &kp ESC,    &kp HOME,   &kp UP,     &kp END,    &kp PG_UP,      &kp INS,    &kp K_APP,  ____xx____, ____xx____, ____xx____, \
    ____xx____, &kp LEFT,   &kp DOWN,   &kp RIGHT,  &kp PG_DN,      &kp BSPC,   MODS_SCAG_____________________________________, \
    SHORTCUTS_UCCPR___________________________________________,     &kp DEL,    ____xx____, VOL_DOWN,   VOL_UP,     VOL_MUTE,   \
                            &kp TAB,    __________, ____xx____,     LAYER_TRANS_______________________


#define LAYER_NUMBER                                                                                                            \
    &kp ESC,    &mkp MB5,   &mkp MB3,   &mkp MB4,   W_SNIP,         &kp COMMA,  &kp N7,     &kp N8,     &kp N9,     &kp FSLH,   \
    MODS_GACS_____________________________________, &mkp MB2,       &kp DOT,    &kp N4,     &kp N5,     &kp N6,     &kp ASTRK,  \
    SHORTCUTS_UCCPR___________________________________________,     &kp MINUS,  &kp N1,     &kp N2,     &kp N3,     &kp PLUS,   \
                            &kp TAB,    __________, &kp SPACE,      &kp N0,     __________, __________


#define LAYER_SYMBOL                                                                                                            \
    &kp CARET,  &kp AT,     MACRO_LGT,  &kp GT,     &kp GRAVE,      &kp PIPE,   MACRO_BRC,  &kp RBRC,   &kp DLLR,   MACRO_DQUO, \
    ____xx____, &kp ASTRK,  &kp FSLH,   &kp EQUAL,  &kp AMPS,       &kp POUND,  MACRO_PAR,  &kp RPAR,   &kp SEMI,   MACRO_SQUO, \
    &kp TILDE,  &kp PLUS,   MACRO_BKT,  &kp RBKT,   &kp PRCNT,      &kp BSLH,   &kp COLON,  &kp QMARK,  &kp EXCL,   &kp MINUS,  \
                            LAYER_TRANS_______________________,     LAYER_TRANS_______________________


#define LAYER_FUNCTION                                                                                                          \
    BT_1,       BT_2,       BT_3,       BT_4,       BT_5,           ____xx____, &kp F7,     &kp F8,     &kp F9,     &kp F10,    \
    MODS_GACS_____________________________________, BT_0,           ____xx____, &kp F4,     &kp F5,     &kp F6,     &kp F11,    \
    BT_CLEAR,   &kp KP_NUM, &kp CAPS,   &kp SLCK,   &kp PSCRN,      ____xx____, &kp F1,     &kp F2,     &kp F3,     &kp F12,    \
                            OUTPUT_TOG, &ind_con,   &ind_bat,       QWERTY,     GRAPHITE,   GAME

//  xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,
