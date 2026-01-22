/*
 * Best Practice: Define reusable constants and macros
 */

#pragma once

// put the default base layers first
#define _QWERTY        0
#define _GRAPHITE      1
#define _GAME          2
#define _GAMENUM       3
#define _NAVIGATION    4
#define _NUMBER        5
#define _SYMBOL        6
#define _FUNCTION      7

// Behavior Configuration
#define TAPPING_TERM          200
#define QUICK_TAP_TERM        150
#define PRIOR_IDLE_TERM       100

#define HRM_TAPPING_TERM      280
#define HRM_QUICK_TAP_TERM    175
#define HRM_PRIOR_IDLE_TERM   130

// layer changes
#define NUMBER         &mo _NUMBER
#define NAVIGATION     &mo _NAVIGATION
#define FUNCTION       &mo _FUNCTION
#define GAMENUM        &mo _GAMENUM

#define QWERTY         &to _QWERTY
#define GRAPHITE       &to _GRAPHITE
#define GAME           &to _GAME

// windows shortcuts
#define W_SNIP         &kp LG(LS(S))

// homerow mods
#define HRML(k1, k2, k3, k4) &hml LGUI k1   &hml LALT k2   &hml LCTRL k3  &hml LSHFT k4
#define HRMR(k1, k2, k3, k4) &hmr RSHFT k1  &hmr RCTRL k2  &hmr RALT k3   &hmr RGUI  k4

// key overrides
#define KO_COMMA             &ht LPAR      COMMA
#define KO_COMMAG            &ht RPAR      COMMA
#define KO_DOT               &ht RPAR      DOT
#define KO_DOTG              &ht RPAR      DOT
#define KO_MINUS             &ht UNDER     MINUS
#define KO_SQT               &ht DQT       SQT

// other shortcuts
#define VOL_UP               &kp C_VOL_UP
#define VOL_DOWN             &kp C_VOL_DN

// wireless connectivity and output modes
#define BT1                  &bt BT_SEL 0
#define BT2                  &bt BT_SEL 1
#define BT3                  &bt BT_SEL 2
#define BT4                  &bt BT_SEL 3
#define BT5                  &bt BT_SEL 4
#define BT6                  &bt BT_SEL 5

#define BT_CLEAR             &bt BT_CLR
#define OUTPUT_BLE           &out OUT_BLE
#define OUTPUT_USB           &out OUT_USB

// YADS Screen Control
#define YADS_SCR             &kp F22
#define YADS_DOWN            &kp F23
#define YADS_UP              &kp F24

// keymap macros
#define __________                                             &trans
#define ____xx____                                             &none
#define _BASE_L4________________________                       &mkp MB1   NUMBER     &kp LSHFT
#define _BASE_R4________________________                       &kp SPACE  NAVIGATION &mkp MB4
#define _LAYER_TRANS____________________                       ____xx____ __________ ____xx____
#define _MODS_GACS_________________________________            &kp LGUI   &kp LALT   &kp LCTRL  &kp LSHFT
#define _MODS_SCAG_________________________________            &kp RSHFT  &kp RCTRL  &kp RALT   &kp RGUI
#define _SHORTCUTS_UCCPR______________________________________ &kp LC(Z)  &kp LC(X)  &kp LC(C)  &kp LC(V)  &kp LC(Y)
#define _NONE_5_______________________________________________ ____xx____ ____xx____ ____xx____ ____xx____ ____xx____


/*
 * Macros - inspired by RafaelRomao
 *
 * Desire:  Want to be able to hold to type a bracket pair with the cursor inside
 * Example: tapping to get '(' and hold to get '()' with the cursor inside
 * 
 * Implementation:
 * - Define macro for the bracket pair
 * - Define new tap hold behavior with the hold hardcoded to the macro
 * - Define new keycode with that taphold behaviorks
 */

#define MACRO(NAME, BINDINGS)                      \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-macro";         \
        #binding-cells = <0>;                      \
        bindings = <BINDINGS>;                     \
    };

//require prior idle ms used to be 125
#define HOLDTAP_MACRO(NAME, HOLD_MACRO)            \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-hold-tap";      \
        flavor = "tap-preferred";                  \
        #binding-cells = <2>;                      \
        tapping-term-ms = <TAPPING_TERM>;          \
        quick-tap-ms = <QUICK_TAP_TERM>;           \
        require-prior-idle-ms = <PRIOR_IDLE_TERM>; \
        bindings = <HOLD_MACRO>, <&kp>;            \
    };


// The 0 is required because we are hard coding the macro but the behavior
// still wants two parameters
#define MACRO_BRC  &ht_brc 0 LBRC
#define MACRO_LGT  &ht_lgt 0 LT
#define MACRO_BKT  &ht_bkt 0 LBKT
#define MACRO_PAR  &ht_par 0 LPAR
#define MACRO_SQUO &ht_sqt 0 SQT
#define MACRO_DQUO &ht_dqt 0 DQT

/*
 * Position definition for timerless home row mods
 *
 *   ╭─────────────────────────┬─────────────────────────╮
 *   │     LT4 LT3 LT2 LT1 LT0 │ RT0 RT1 RT2 RT3 RT4     │
 *   │     LM4 LM3 LM2 LM1 LM0 │ RM0 RM1 RM2 RM3 RM4     │
 *   │ LB5 LB4 LB3 LB2 LB1 LB0 │ RB0 RB1 RB2 RB3 RB4 RB5 │
 *   ╰───────────╮ LH2 LH1 LH0 │ RH0 RH1 RH2 ╭───────────╯
 *               ╰─────────────┴─────────────╯
 */

#define LT4 0
#define LT3 1
#define LT2 2
#define LT1 3
#define LT0 4

#define RT0 5
#define RT1 6
#define RT2 7
#define RT3 8
#define RT4 9

#define LM4 10
#define LM3 11
#define LM2 12
#define LM1 13
#define LM0 14

#define RM0 15
#define RM1 16
#define RM2 17
#define RM3 18
#define RM4 19

#define LB5 20
#define LB4 21
#define LB3 22
#define LB2 23
#define LB1 24
#define LB0 25

#define RB0 26
#define RB1 27
#define RB2 28
#define RB3 29
#define RB4 30
#define RB5 31

#define LH2 32
#define LH1 33
#define LH0 34

#define RH0 35
#define RH1 36
#define RH2 37

#define KEYS_L LT4 LT3 LT2 LT1 LT0 LM4 LM3 LM2 LM1 LM0 LB5 LB4 LB3 LB2 LB1 LB0
#define KEYS_R RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4 RB5
#define THUMBS LH2 LH1 LH0 RH0 RH1 RH2

