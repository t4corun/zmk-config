/*
 * Best Practice: Define reusable constants and macros
 */

#pragma once

// put the default base layers first
#define _QWERTY        0
#define _GRAPHITE      1
#define _NAVIGATION    2
#define _NUMBER        3
#define _SYMBOL        4
#define _FUNCTION      5

// Behavior Configuration
#define TAPPING_TERM          200
#define QUICK_TAP_TERM        150
#define PRIOR_IDLE_TERM       100

// layer changes
#define NUMBER         &mo _NUMBER
#define NAVIGATION     &mo _NAVIGATION
#define FUNCTION       &mo _FUNCTION

#define QWERTY         &to _QWERTY
#define GRAPHITE       &to _GRAPHITE

// navigation
#define NEXT_TAB       &kp LC(TAB)
#define PREV_TAB       &kp LS(LC(TAB))

// key overrides
#define KO_COMMA             &ht LPAR      COMMA
#define KO_COMMAG            &ht RPAR      COMMA
#define KO_DOT               &ht RPAR      DOT
#define KO_DOTG              &ht LPAR      DOT
#define KO_MINUS             &ht UNDER     MINUS
#define KO_SQT               &ht DQT       SQT

// other shortcuts
#define VOL_UP               &kp C_VOL_UP
#define VOL_DOWN             &kp C_VOL_DN
#define VOL_MUTE             &kp C_MUTE

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
#define _BASE_L4________________________                       &mkp MB1   NAVIGATION     &sk LSHFT
#define _BASE_R4________________________                       &kp SPACE  NUMBER         &kp ENTER
#define _LAYER_TRANS____________________                       ____xx____ __________ ____xx____
#define _MODS_GACS_________________________________            &sk LGUI   &sk LALT   &sk LCTRL  &sk LSHFT
#define _MODS_SCAG_________________________________            &sk RSHFT  &sk RCTRL  &sk RALT   &sk RGUI
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