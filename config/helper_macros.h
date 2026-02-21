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

#define MACRO(NAME, BINDINGS)                              \
    NAME: NAME {                                           \
        compatible = "zmk,behavior-macro";                 \
        #binding-cells = <0>;                              \
        bindings = <BINDINGS>;                             \
    };

//require prior idle ms used to be 125
#define HOLDTAP_MACRO(NAME, HOLD_MACRO)                    \
    NAME: NAME {                                           \
        compatible = "zmk,behavior-hold-tap";              \
        flavor = "tap-preferred";                          \
        #binding-cells = <2>;                              \
        tapping-term-ms = <TAPPING_TERM>;                  \
        quick-tap-ms = <QUICK_TAP_TERM>;                   \
        require-prior-idle-ms = <PRIOR_IDLE_TERM>;         \
        bindings = <HOLD_MACRO>, <&kp>;                    \
    };

#define MOD_MORPH(NAME, TAP, MORPH, MODS)                  \
    NAME: NAME {                                           \
        compatible = "zmk,behavior-mod-morph";             \
        #binding-cells = <0>;                              \
        bindings = <TAP>, <MORPH>;                         \
        mods = <MODS>;                                     \
    };

#define COMBO_MACRO(NAME, POSITIONS, LAYERS, BINDINGS)     \
    / {                                                    \
        combos {                                           \
            compatible = "zmk,combos";                     \
            combo_ ## NAME {                               \
                timeout-ms = <COMBO_TIMEOUT>;              \
                key-positions = <POSITIONS>;               \
                layers = <LAYERS>;                         \
                bindings = <BINDINGS>;                     \
                require-prior-idle-ms = <PRIOR_IDLE_TERM>; \
            };                                             \
        };                                                 \
    };
