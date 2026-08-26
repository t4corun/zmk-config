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
                         lh3,    rh3,                          \
                    lt5, lm5,    rt5, rm5                      \
)                                                              \
lt5  lt4  lt3  lt2  lt1  lt0     rt0  rt1  rt2  rt3  rt4  rt5  \
lm5  lm4  lm3  lm2  lm1  lm0     rm0  rm1  rm2  rm3  rm4  rm5  \
     lb4  lb3  lb2  lb1  lb0     rb0  rb1  rb2  rb3  rb4       \
          lh3  lh2  lh1  lh0     rh0  rh1  rh2  rh3


/*
 * Position definition for timerless home row mods
 *
 *   ╭─────────────────────────┬─────────────────────────╮
 *   │ LT5 LT4 LT3 LT2 LT1 LT0 │ RT0 RT1 RT2 RT3 RT4 RT5 │
 *   │ LM5 LM4 LM3 LM2 LM1 LM0 │ RM0 RM1 RM2 RM3 RM4 RM5 │
 *   │     LB4 LB3 LB2 LB1 LB0 │ RB0 RB1 RB2 RB3 RB4     │
 *   ╰───────╮ LH3 LH2 LH1 LH0 │ RH0 RH1 RH2 RH3 ╭───────╯
 *           ╰─────────────────┴─────────────────╯
 */

#define LT5 0 
#define LT4 1
#define LT3 2
#define LT2 3
#define LT1 4
#define LT0 5

#define RT0 6
#define RT1 7
#define RT2 8
#define RT3 9
#define RT4 10
#define RT5 11

#define LM5 12
#define LM4 13
#define LM3 14
#define LM2 15
#define LM1 16
#define LM0 17

#define RM0 18
#define RM1 19
#define RM2 20
#define RM3 21
#define RM4 22
#define RM5 23

#define LB4 24
#define LB3 25
#define LB2 26
#define LB1 27
#define LB0 28

#define RB0 29
#define RB1 30
#define RB2 31
#define RB3 32
#define RB4 33

#define LH3 34
#define LH2 35
#define LH1 36
#define LH0 37

#define RH0 38
#define RH1 39
#define RH2 40
#define RH3 41

#define KEYS_L   LT5 LT4 LT3 LT2 LT1 LT0 LM5 LM4 LM3 LM2 LM1 LM0 LB4 LB3 LB2 LB1 LB0
#define KEYS_R   RT0 RT1 RT2 RT3 RT4 RT5 RM0 RM1 RM2 RM3 RM4 RM5 RB0 RB1 RB2 RB3 RB4
#define THUMBS   LH3 LH2 LH1 LH0 RH0 RH1 RH2 RH3
#define HRM_NONE LH0
#define HRM_RALT LB2 LB1
#define HRM_GUI  RH0