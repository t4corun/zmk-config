/*
 * Wrapper to expand my keymap into keyboard specific keymaps
 *
 * This makes it easier to change the keymap in one place (t4corun.h)
 * and reduces duplication
 */

#define TEMPORAL_WRAPPER(...) \
    TEMPORAL_LAYOUT(__VA_ARGS__)

#define TEMPORAL_LAYOUT(                                       \
     lt4, lt3, lt2, lt1, lt0,    rt0, rt1, rt2, rt3, rt4,      \
     lm4, lm3, lm2, lm1, lm0,    rm0, rm1, rm2, rm3, rm4,      \
     lb4, lb3, lb2, lb1, lb0,    rb0, rb1, rb2, rb3, rb4,      \
               lh2, lh1, lh0,    rh0, rh1, rh2,                \
                         lh3,    rh3                           \
)                                                              \
     lt4  lt3  lt2  lt1  lt0     rt0  rt1  rt2  rt3  rt4       \
     lm4  lm3  lm2  lm1  lm0     rm0  rm1  rm2  rm3  rm4       \
     lb4  lb3  lb2  lb1  lb0     rb0  rb1  rb2  rb3  rb4       \
          lh3  lh2  lh1  lh0     rh0  rh1  rh2  rh3

/*
 * Position definition for timerless home row mods
 *
 *   ╭─────────────────────┬─────────────────────╮
 *   │ LT4 LT3 LT2 LT1 LT0 │ RT0 RT1 RT2 RT3 RT4 │
 *   │ LM4 LM3 LM2 LM1 LM0 │ RM0 RM1 RM2 RM3 RM4 │
 *   │ LB4 LB3 LB2 LB1 LB0 │ RB0 RB1 RB2 RB3 RB4 │
 *   ╰───╮ LH3 LH2 LH1 LH0 │ RH0 RH1 RH2 RH3 ╭───╯
 *       ╰─────────────────┴─────────────────╯
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

#define LB4 20
#define LB3 21
#define LB2 22
#define LB1 23
#define LB0 24

#define RB0 25
#define RB1 26
#define RB2 27
#define RB3 28
#define RB4 29

#define LH3 30
#define LH2 31
#define LH1 32
#define LH0 33

#define RH0 34
#define RH1 35
#define RH2 36
#define RH3 37

#define KEYS_L    LT4 LT3 LT2 LT1 LT0 LM4 LM3 LM2 LM1 LM0 LB4 LB3 LB2 LB1 LB0
#define KEYS_R    RT0 RT1 RT2 RT3 RT4 RM0 RM1 RM2 RM3 RM4 RB0 RB1 RB2 RB3 RB4
#define THUMBS    LH3 LH2 LH1 LH0 RH0 RH1 RH2 RH3
#define HRM_NONE  LH3
#define HRM_SHFT  LH2
#define HRM_GUI   RH0
#define HRM_LCTRL LH2 RH0 RH2
#define HRM_RALT  LB2 LB1
