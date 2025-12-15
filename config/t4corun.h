/*
 * Best Practice: Define reusable constants and macros
 */

#pragma once

// put the default base layers first
#define _QWERTY        0
#define _GALLIUM       1
#define _NAVIGATION    2
#define _NUMBER        3
#define _SYMBOL        4
#define _FUNCTION      5

// Behavior Configuration
#define TAPPING_TERM   280
#define QUICK_TAP_TERM 175
#define IDLE_TERM      150

// layer changes
#define NUM            &mo _NUMBER
#define NAV            &mo _NAVIGATION
#define FUNC           &mo _FUNCTION

#define QWERTY         &to _QWERTY
#define GALLIUM        &to _GALLIUM

// windows shortcuts
#define W_SNIP         &kp LG(LS(S))

// homerow mods
#define HRML(k1, k2, k3, k4) &hmlo LGUI k1   &hmlo LALT k2   &hml  LCTRL k3  &hml  LSHFT k4
#define HRMR(k1, k2, k3, k4) &hmr  RSHFT k1  &hmr  RCTRL k2  &hmro RALT k3   &hmro RGUI  k4

// key overrides
#define KO_COMMA             &ht LPAR      COMMA
#define KO_DOT               &ht RPAR      DOT
#define KO_MINUS             &ht UNDER     MINUS

// wireless connectivity and output modes
#define BT1                  &bt BT_SEL 0
#define BT2                  &bt BT_SEL 1
#define BT3                  &bt BT_SEL 2
#define BT4                  &bt BT_SEL 3
#define BT5                  &bt BT_SEL 4

#define BT_CLEAR             &bt BT_CLR
#define OUTPUT_BLE           &out OUT_BLE
#define OUTPUT_USB           &out OUT_USB

// keymap macros
#define __________                                             &trans
#define ____xx____                                             &none
#define _BASE_L4________________________                       &kp TAB    NUM        &kp LSHFT
#define _BASE_R4________________________                       &kp SPACE  NAV        &kp BSPC
#define _LAYER_TRANS____________________                       ____xx____ __________ ____xx____
#define _MODS_GACS_________________________________            &kp LGUI   &kp LALT   &kp LCTRL  &kp LSHFT
#define _MODS_SCAG_________________________________            &kp RSHFT  &kp RCTRL  &kp RALT   &kp RGUI
#define _SHORTCUTS_UCCPR______________________________________ &kp LC(Z)  &kp LC(X)  &kp LC(C)  &kp LC(V)  &kp LC(Y)
#define _NONE_5_______________________________________________ ____xx____ ____xx____ ____xx____ ____xx____ ____xx____


/*
 * Behavior Macros
 */

#define HRM(NAME, TERM, POSITIONS) \
    NAME: NAME { \
        compatible = "zmk,behavior-hold-tap"; \
        #binding-cells = <2>; \
        flavor = "balanced"; \
        tapping-term-ms = TERM; \
        hold-trigger-key-positions = POSITIONS; \
        hold-trigger-on-release; \
        require-prior-idle-ms = <IDLE_TERM>; \
        quick-tap-ms = <QUICK_TAP_TERM>; \
        bindings = <&kp>, <&kp>; \
    };

/*
 * Macros - borrowed from RafaelRomao
 *
 * This is the only way I found to get my cursor macros to work
 * For example doing '()' and putting the cursor inside
 * 
 * What happens is that we define a macro for the tap '(' and a
 * macro for the hold '( ) left'. Then send both macros into the
 * HOLDTAP
 */

#define MACRO(NAME, BINDINGS) \
    NAME: NAME { \
        compatible = "zmk,behavior-macro"; \
        #binding-cells = <0>; \
        wait-ms = <5>; \
        tap-ms = <5>; \
        bindings = <BINDINGS>; \
    };

//require prior idle ms used to be 125
#define HOLDTAP(NAME, HOLD, TAP) \
    NAME: NAME { \
        compatible = "zmk,behavior-hold-tap"; \
        flavor = "tap-preferred"; \
        #binding-cells = <2>; \
        tapping-term-ms = <TAPPING_TERM>; \
        quick-tap-ms = <QUICK_TAP_TERM>; \
        require-prior-idle-ms = <50>; \
        bindings = <HOLD>, <TAP>; \
    };


// The 0 0 is required but I do not know the reasoning behind it
#define MACRO_BRC  &ht_brc 0 0
#define MACRO_LGT  &ht_lgt 0 0
#define MACRO_BKT  &ht_bkt 0 0
#define MACRO_PAR  &ht_par 0 0
#define MACRO_SQUO &ht_sqt 0 0
#define MACRO_DQUO &ht_dqt 0 0

/*
 * Position definition for timerless home row mods
 * Borred from urob and caksoylar
 *
 * The naming matches the totem's matrx-transform positions
 */

#define L00 0
#define L01 1
#define L02 2
#define L03 3
#define L04 4

#define R05 5
#define R06 6
#define R07 7
#define R08 8
#define R09 9

#define L10 10
#define L11 11
#define L12 12
#define L13 13
#define L14 14

#define R15 15
#define R16 16
#define R17 17
#define R18 18
#define R19 19

#define L30 20
#define L20 21
#define L21 22
#define L22 23
#define L23 24
#define L24 25

#define R25 26
#define R26 27
#define R27 28
#define R28 29
#define R29 30
#define R39 31

#define L32 32
#define L33 33
#define L34 34

#define R35 35
#define R36 36
#define R37 37

#define KEYS_L <L00 L01 L02 L03 L04 L10 L11 L12 L13 L14 L30 L20 L21 L22 L23 L24 L32 L33 L34>
#define KEYS_R <R05 R06 R07 R08 R09 R15 R16 R17 R18 R19 R25 R26 R27 R28 R29 R39 R35 R36 R37>