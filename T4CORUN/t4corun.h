#pragma once

// Layer Definitions out toggle
#define QWERTY  0
#define COLEMAK 1
#define NUMBER  2
#define NAVI    3
#define SYMBOL  4
#define MOUSE	5
#define CONFIG  6

//new stuff
#define MOU(keycode) 	&lt MOUSE 	keycode
#define NAV(keycode) 	&lt NAVI 	keycode

//To Layer
#define DEFAULT			&to 		QWERTY
#define CLMAKDH 		&to	    	COLEMAK

//Shortcuts
#define W_UNDO  		&kp 		LC(Z)
#define W_CUT   		&kp 		LC(X)
#define W_COPY  		&kp 		LC(C)
#define W_PASTE 		&kp 		LC(V)
#define W_REDO  		&kp 		LC(Y)
#define W_SNIP  		&kp 		LS(LG(S))
#define W_FILE  		&kp 		LG(E)

#define NEXTTAB 		&kp 		LC(TAB)

//Bluetooth
#define BTClear 		&bt 		BT_CLR
#define BT0     		&bt 		BT_SEL 0
#define BT1     		&bt 		BT_SEL 1
#define BT2     		&bt 		BT_SEL 2
#define BT3     		&bt 		BT_SEL 3
#define BT4     		&bt 		BT_SEL 4

//Behavior Configuration
#define QUICK_TAP_TERM 		125
#define TAPPING_TERM 		200
#define COMBO_TIMEOUT 		50
#define STICKYKEY_TIMEOUT 	2000


#define COMBO(name, keypress, pos)  \
combo_##name {                      \
    timeout-ms    = <COMBO_TIMEOUT>;\
	layers 		  = <QWERTY>;		\
    bindings      = <keypress>;     \
    key-positions = <pos>;          \
};


#define HOLD_TAP(name, hold_tap_flavor, hold, tap) 			\
name: name##_hold_tap { 									\
    compatible      = "zmk,behavior-hold-tap"; 				\
	label           = ZMK_MACRO_STRINGIFY(name)				\
    flavor          = ZMK_MACRO_STRINGIFY(hold_tap_flavor);	\
    tapping-term-ms = <TAPPING_TERM>;         				\
    quick-tap-ms    = <QUICK_TAP_TERM>;       				\
    #binding-cells  = <2>;                    				\
    bindings        = <hold>, <tap>;    	      			\
};

//#define HOLD_TAP(name, hold_tap_flavor, hold, tap) name: name##_hold_tap { compatible = "zmk,behavior-hold-tap"; label = #name; flavor = #hold_tap_flavor; tapping-term-ms = <TAPPING_TERM>; quick-tap-ms = <QUICK_TAP_TERM>; #binding-cells = <2>; bindings = <hold>, <tap>; };

#define HT(holdkey, tapkey)		&ht 	holdkey, 	tapkey
#define DT(keycode) 			&dt 	keycode, 	keycode	
#define DTL(keycode) 			&dtl 	keycode, 	keycode
#define DTS(keycode)			&dts	keycode, 	keycode
#define TRI(keycode)			&tri	keycode, 	keycode

#define LRBRC(keycode)			&lrbrc 	&none, 		keycode
#define LRBKT(keycode)			&lrbkt 	&none, 		keycode
#define LRPAR(keycode)			&lrpar 	&none, 		keycode
#define LGT(keycode)			&lgt 	&none, 		keycode
#define NE(keycode)				&ne 	&none, 		keycode

#define TAP_DANCE(name, sequence)  					 \
name: name##_tap_dance {                       		 \
    compatible      = "zmk,behavior-tap-dance";		 \
	label           = #name;                  		 \
    #binding-cells  = <0>;                    		 \
    tapping-term-ms = <TAPPING_TERM>;         		 \
    bindings        = sequence;         	 		 \
};
