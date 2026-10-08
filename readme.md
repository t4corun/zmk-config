# t4corun ZMK Config

Home of my firmware for the GEIST TOTEM and Curbol Temporal split keyboards

## Hardware

<img src="images/temporal_twins.jpeg" alt="the twins" width="800">
<img src="images/totem_temporal.png" alt="the family" width="800">

The TOTEM was built first and is a straight forward 38-key split keyboard with splay. The peripheral splits and central dongle all use a Seeed Xiao BLE MCU

The Temporal came later. Mine is the 37-key version of this split keyboard with splay. The right side has an encoder and Azoteq TPS43 multi-touch trackpad. The left side has a Nice!View display. Both peripheral splits use a Nice!Nano v2 MCU and the dongle uses the Seeed Xiao BLE MCU. I built it for travel because it is smaller than the TOTEM, and I find its thumb cluster more comfortable (more splay).

## Firmware

This is a port of my QMK Firmware keymap. It is inspired by Miryoku and designed with SQL and Powershell in mind. It features

- Supports Zephyr 4.1
- Builds dongle firmware for Prospector and RGB Widget
- Macros for brackets (e.g. type {} and placed the cursor inside)
- urob's Timerless homerow mods
- urob Numword

Wrote the sheild definitions and configuration files to make it as lean as possible. I have done more, however the seemingly duplicate files are there to mental load later figuring out what is going on

## Layout

<img src="images/totem.png" alt="keymap" width="600">

## Learnings

General Learnings

- The order of includes isn't strict
- The trackpad must have a code remap behavior or mouse movements will act as a drag click

The trackpad eats power. I had the below refresh rates with the default timeout settings and I would be dead after 3-4 days.

```text
report-rate-active = <10>;
report-rate-idle-touch = <50>;
report-rate-idle = <50>;
report-rate-lp1 = <80>;
report-rate-lp2 = <250>;

0-5s: active 100Hz
5-65s: idle-touch 20Hz
65-75s: idle 20Hz
75-95s: lp1 12.5Hz
95s on: lp2 6.25Hz
```





## Wishlist

- Can we do OS mod swap like QMK?

## TPS43 Defaults

With no additional settings these are the defaults. Units come from the `azoteq,tps43-common.yaml` binding where defined.

| Setting | Value |
| --- | --- |
| SYSTEM_INFO_0 | 210 |
| SYSTEM_INFO_1 | 0 |
| SYSTEM_CONTROL_0 | 160 |
| SYSTEM_CONTROL_1 | 0 |
| SYSTEM_CONFIG_0 | 100 |
| SYSTEM_CONFIG_1 | 69 |
| GLOBAL_ATI_C | 1 |
| ATI_TARGET | 700 count |
| REF_DRIFT_LIMIT | 75 |
| REATI_LOWER_LIMIT | 0 count |
| REATI_UPPER_LIMIT | 255 count |
| MAX_COUNT_LIMIT | 2000 count |
| ATI_RETRY_TIME | 5 s |
| REPORT_RATE_ACTIVE | 13 ms |
| REPORT_RATE_IDLE_TOUCH | 50 ms |
| REPORT_RATE_IDLE | 50 ms |
| REPORT_RATE_LP1 | 80 ms |
| REPORT_RATE_LP2 | 160 ms |
| TIMEOUT_ACTIVE | 5 s |
| TIMEOUT_IDLE_TOUCH | 60 s |
| TIMEOUT_IDLE | 10 s |
| TIMEOUT_LP1 | 1 (20 s units) |
| REF_UPDATE_TIME | 8 s |
| XY_STATIC_BETA | 128 |
| ALP_COUNT_BETA | 50 |
| ALP1_LTA_BETA | 8 |
| ALP2_LTA_BETA | 6 |
| XY_DYNAMIC_FILTER_BOTTOM | 7 |
| XY_DYNAMIC_FILTER_LOWER | 6 |
| XY_DYNAMIC_FILTER_UPPER | 250 |
| X_RESOLUTION | 1024 px |
| Y_RESOLUTION | 1024 px |
| TAP_TIME | 150 ms |
| TAP_DISTANCE | 25 px |
| HOLD_TIME | 300 ms |
| SWIPE_INITIAL_TIME | 150 ms |
| SWIPE_INITIAL_DISTANCE | 300 px |
| SWIPE_CONSECUTIVE_TIME | 0 ms |
| SWIPE_CONSECUTIVE_DISTANCE | 2000 px |
| SWIPE_ANGLE | 23 deg |
| SCROLL_INITIAL_DISTANCE | 50 px |
| SCROLL_ANGLE | 37 deg |
| ZOOM_INITIAL_DISTANCE | 50 px |
| ZOOM_CONSECUTIVE_DISTANCE | 25 px |

Raw Logs

```text
[00:00:01.061,614] <inf> tps43: Dumping TPS43 registers
[00:00:01.061,859] <inf> tps43: SYSTEM_INFO_0 (0x000F): 0xD2
[00:00:01.062,103] <inf> tps43: SYSTEM_INFO_1 (0x0010): 0x00
[00:00:01.062,347] <inf> tps43: SYSTEM_CONTROL_0 (0x0431): 0xA0
[00:00:01.062,622] <inf> tps43: SYSTEM_CONTROL_1 (0x0432): 0x00
[00:00:01.062,866] <inf> tps43: SYSTEM_CONFIG_0 (0x058E): 0x64
[00:00:01.063,110] <inf> tps43: SYSTEM_CONFIG_1 (0x058F): 0x45
[00:00:01.063,354] <inf> tps43: GLOBAL_ATI_C (0x056B): 0x01
[00:00:01.063,629] <inf> tps43: ATI_TARGET (0x056D): 0x02BC
[00:00:01.063,903] <inf> tps43: REF_DRIFT_LIMIT (0x0571): 0x4B
[00:00:01.064,147] <inf> tps43: REATI_LOWER_LIMIT (0x0573): 0x00
[00:00:01.064,392] <inf> tps43: REATI_UPPER_LIMIT (0x0574): 0xFF
[00:00:01.064,666] <inf> tps43: MAX_COUNT_LIMIT (0x0575): 0x07D0
[00:00:01.064,941] <inf> tps43: ATI_RETRY_TIME (0x0577): 0x05
[00:00:01.065,216] <inf> tps43: REPORT_RATE_ACTIVE (0x057A): 0x000D
[00:00:01.065,490] <inf> tps43: REPORT_RATE_IDLE_TOUCH (0x057C): 0x0032
[00:00:01.065,795] <inf> tps43: REPORT_RATE_IDLE (0x057E): 0x0032
[00:00:01.066,070] <inf> tps43: REPORT_RATE_LP1 (0x0580): 0x0050
[00:00:01.066,345] <inf> tps43: REPORT_RATE_LP2 (0x0582): 0x00A0
[00:00:01.066,619] <inf> tps43: TIMEOUT_ACTIVE (0x0584): 0x05
[00:00:01.066,864] <inf> tps43: TIMEOUT_IDLE_TOUCH (0x0585): 0x3C
[00:00:01.067,108] <inf> tps43: TIMEOUT_IDLE (0x0586): 0x0A
[00:00:01.067,352] <inf> tps43: TIMEOUT_LP1 (0x0587): 0x01
[00:00:01.067,596] <inf> tps43: REF_UPDATE_TIME (0x0588): 0x08
[00:00:01.067,871] <inf> tps43: XY_STATIC_BETA (0x0633): 0x80
[00:00:01.068,115] <inf> tps43: ALP_COUNT_BETA (0x0634): 0x32
[00:00:01.068,359] <inf> tps43: ALP1_LTA_BETA (0x0635): 0x08
[00:00:01.068,603] <inf> tps43: ALP2_LTA_BETA (0x0636): 0x06
[00:00:01.068,878] <inf> tps43: XY_DYNAMIC_FILTER_BOTTOM (0x0637): 0x07
[00:00:01.069,122] <inf> tps43: XY_DYNAMIC_FILTER_LOWER (0x0638): 0x06
[00:00:01.069,396] <inf> tps43: XY_DYNAMIC_FILTER_UPPER (0x0639): 0x00FA
[00:00:01.069,671] <inf> tps43: X_RESOLUTION (0x066E): 0x0400
[00:00:01.069,976] <inf> tps43: Y_RESOLUTION (0x0670): 0x0400
[00:00:01.070,251] <inf> tps43: TAP_TIME (0x06B9): 150 ms
[00:00:01.070,526] <inf> tps43: TAP_DISTANCE (0x06BB): 25 px
[00:00:01.070,831] <inf> tps43: HOLD_TIME (0x06BD): 300 ms
[00:00:01.071,105] <inf> tps43: SWIPE_INITIAL_TIME (0x06BF): 150 ms
[00:00:01.071,380] <inf> tps43: SWIPE_INITIAL_DISTANCE (0x06C1): 300 px
[00:00:01.071,685] <inf> tps43: SWIPE_CONSECUTIVE_TIME (0x06C3): 0 ms
[00:00:01.071,960] <inf> tps43: SWIPE_CONSECUTIVE_DISTANCE (0x06C5): 2000 px
[00:00:01.072,204] <inf> tps43: SWIPE_ANGLE (0x06C7): 0x17
[00:00:01.072,509] <inf> tps43: SCROLL_INITIAL_DISTANCE (0x06C8): 50 px
[00:00:01.072,753] <inf> tps43: SCROLL_ANGLE (0x06CA): 0x25
[00:00:01.073,028] <inf> tps43: ZOOM_INITIAL_DISTANCE (0x06CB): 50 px
[00:00:01.073,333] <inf> tps43: ZOOM_CONSECUTIVE_DISTANCE (0x06CD): 25 px
[00:00:01.073,486] <inf> tps43: TPS43 driver successfully initialized
```


### Special Thanks

geigeigeist and curbol for making a beautiful, well documented keyboard, and making it free
eigatech, for sharing the dongle code
rafaelromao, for the macro helpers
urob for the timerless setup, autolayer for numword
caksoylar for the general organization and rgbled widget
holykeebs for making the azoteq tps43 trackpad kit
geeksville for the trackpad driver
beekeeb for the trackpad implementation example
jlcpcb for the beautiful prints

