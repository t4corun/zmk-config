#pragma once

enum layers {
  _QWERTY = 0,
  FIRST_DEFAULT_LAYER = 0,
  _COLEMAK_DH,
  _GAMING,
  _NUMBER,
  _NAVIGATION,
  _FUNCTION,
  _MOUSE,
  _GAMENUMBER,
  _ADJUST
};

// Layer Definitions out toggle
#define QWERTY  0
#define COLEMAK 1
#define NUMBER  2
#define NAVI    3
#define FUNC    4
#define MOUSE	5
#define ADJUST  6

//Basic Key Aliases
#define ___________     &trans
#define _____x_____     &none

//Layer Taps
#define MOU_SPC &lt     MOUSE   SPACE
#define MOU_N	&lt		MOUSE	N
#define MOU_K	&lt		MOUSE	K
#define NAV_TAB &lt     NAVI    TAB
#define NUM_BSP &lt     NUMBER  BSPC
#define FUN_Z   &lt_pky FUNC    Z
#define AD_FSLH &lt_pky	ADJUST  FSLH

//Mod Taps
#define NUM_LYR &mo		NUMBER

//To Layer
#define DEFAULT &to 	_QWERTY
#define COLMKDH &to	    _COLEMAK_DH

//Shortcuts
#define S_UNDO  &kp LC(Z)
#define S_CUT   &kp LC(X)
#define S_COPY  &kp LC(C)
#define S_PASTE &kp LC(V)
#define S_REDO  &kp LC(Y)

#define CLSETAB &kp LC(W)
#define NEXTTAB &kp LC(TAB)
#define PREVTAB &kp LC(LS(TAB))

//Bluetooth
#define BTClear &bt BT_CLR
#define BT0     &bt BT_SEL 0
#define BT1     &bt BT_SEL 1
#define BT2     &bt BT_SEL 2
#define BT3     &bt BT_SEL 3
#define BT4     &bt BT_SEL 4

//Behavior Configuration
#define QUICK_TAP_TERM 125
#define TAPPING_TERM 200
#define TAPPING_TERM_GUIALT 230
#define TAPPING_TERM_PINKY 250

