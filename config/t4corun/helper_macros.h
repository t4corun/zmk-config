/*
 * Macros - inspired by RafaelRomao
 /

 /
 * Bracket Hold
 * 
 * Desire:
 *   Want to be able to hold to type a bracket pair
 *   with the cursor inside
 *
 * Example:
 *   tapping to get '(' and hold to get '()' with 
 *   the cursor inside
 * 
 * Implementation:
 * - Define macro for the bracket pair
 * - Define new tap hold behavior with the hold 
 *     hardcoded to the macro
 * - Define new keycode with that taphold behavior
 */

#define MACRO(                                     \
            NAME                                   \
            , BINDINGS                             \
        )                                          \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-macro";         \
        #binding-cells = <0>;                      \
        bindings = <BINDINGS>;                     \
    };

//require prior idle ms used to be 125
#define HOLDTAP_MACRO(                             \
            NAME                                   \
            , HOLD_MACRO                           \
        )                                          \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-hold-tap";      \
        flavor = "tap-preferred";                  \
        #binding-cells = <2>;                      \
        tapping-term-ms = <TAPPING_TERM>;          \
        quick-tap-ms = <QUICK_TAP_TERM>;           \
        require-prior-idle-ms = <PRIOR_IDLE_TERM>; \
        bindings = <HOLD_MACRO>, <&kp>;            \
    };

/*
 * Home Row Mod for Urob Timerless
 */

#define HRM_MACRO(                                 \
            NAME                                   \
            , TAP_TERM                             \
            , POSITIONS                            \
        )                                          \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-hold-tap";      \
        #binding-cells = <2>;                      \
        flavor = "balanced";                       \
        require-prior-idle-ms = <PRIOR_IDLE_TERM>; \
        tapping-term-ms = <TAP_TERM>;              \
        quick-tap-ms = <QUICK_TAP_TERM>;           \
        bindings = <&kp>, <&kp>;                   \
        hold-trigger-key-positions = <POSITIONS>;  \
        hold-trigger-on-release;                   \
    };

/*
 * Key override defintions
 */

#define MOD_MORPH(                                 \
            NAME                                   \
            , TAP                                  \
            , MORPH                                \
            , MODS                                 \
        )                                          \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-mod-morph";     \
        #binding-cells = <0>;                      \
        bindings = <TAP>, <MORPH>;                 \
        mods = <MODS>;                             \
    };

/*
 * Combo Definitions
 */

#define COMBO_MACRO(                               \
            NAME                                   \
            , POSITIONS                            \
            , LAYERS                               \
            , BINDINGS                             \
        )                                          \
    / {                                            \
        combos {                                   \
            compatible = "zmk,combos";             \
            combo_ ## NAME {                       \
                timeout-ms = <COMBO_TIMEOUT>;      \
                key-positions = <POSITIONS>;       \
                layers = <LAYERS>;                 \
                bindings = <BINDINGS>;             \
                require-prior-idle-ms =            \
                    <PRIOR_IDLE_TERM>;             \
            };                                     \
        };                                         \
    };

/*
 * Encoder Macros
 *
 * MOD_TAP_MACRO:
 *   configurable to hold a mod(s) and tap a key
 *
 * Example:
 *   Zoom by doing CTRL + = or CTRL + -
 *
 *
 * ROTATE_MACRO:
 *   Defining encoder rotation for non key presses
 */

#define MOD_TAP_MACRO(                             \
            NAME                                   \
            , MOD                                  \
            , TAP                                  \
            , TAP_TIME                             \
            , WAIT_TIME                            \
        )                                          \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-macro";         \
        #binding-cells = <0>;                      \
        tap-ms = <TAP_TIME>;                       \
        wait-ms = <WAIT_TIME>;                     \
        bindings =                                 \
              <&macro_press &kp MOD>               \
            , <&macro_tap &kp TAP>                 \
            , <&macro_release &kp MOD>;            \
    };

#define ROTATE_MACRO(                              \
            NAME                                   \
            , CW                                   \
            , CCW                                  \
            , TAP_TIME                             \
        )                                          \
    NAME: NAME {                                   \
        compatible = "zmk,behavior-sensor-rotate"; \
        #sensor-binding-cells = <0>;               \
        #tap-ms = <TAP_TIME>;                      \
        bindings = <CW>, <CCW>;                    \
    };
