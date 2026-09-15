# Temporal Trackpad Debugging: INPUT_BTN_TOUCH Click-Drag Issue

## Problem Statement
When moving the mouse on the trackpad, the firmware registers a continuous left-click drag instead of pure mouse movement. The finger touching and moving the trackpad acts like holding down the left mouse button while dragging.

## Investigation Process

### Initial Symptoms
- Disabling `press-and-hold` gesture: No improvement
- Disabling `single-tap` gesture: No improvement  
- Disabling all gestures (zoom, scroll, two-finger-tap, etc.): Still persists

### Root Cause Analysis

The issue is **not** caused by gesture configuration. After examining the driver source code (`C:\Repo\temp\zmk_driver_azoteq\drivers\input\tps43.c`), the culprit was found:

```c
bool is_touching = (num_fingers > 0);
if (is_touching != drv_data->touching) {
    drv_data->touching = is_touching;
    LOG_INF("Touch state changed: %s", is_touching ? "down" : "up");
    input_report_key(dev, INPUT_BTN_TOUCH, is_touching ? 1 : 0, true, K_FOREVER);
}
```

**The driver unconditionally reports `INPUT_BTN_TOUCH` whenever a finger touches or leaves the pad, regardless of gesture settings.** This happens in the main touch handler and cannot be disabled via device tree configuration.

The sequence of events:
1. Finger touches pad → `INPUT_BTN_TOUCH` = 1 (button pressed)
2. Finger moves → relative X/Y events reported while button is held
3. Finger lifts → `INPUT_BTN_TOUCH` = 0 (button released)

Result: ZMK interprets this as holding down the left mouse button while moving, creating a drag operation.

## Solutions Explored

### Solution 1: Filter INPUT_BTN_TOUCH with Input Processor (✅ Recommended)
Use ZMK's `input-processor-key-filter` to strip out `INPUT_BTN_TOUCH` events before they reach the input system.

In `config/t4corun/trackpad.dtsi`:
```devicetree
touch_filter: touch_filter {
    compatible = "zmk,input-processor-key-filter";
    #input-processor-cells = <0>;
    codes = <INPUT_BTN_TOUCH>;
};

&trackpad_listener {
    input-processors = <&touch_filter>,
                       <&zip_xy_scaler 1 1>;
};
```

**Pros:**
- Simple configuration change
- No driver modification required
- Clean separation of concerns
- Pure mouse movement without any touch feedback

**Cons:**
- Loses touch detection (but trackpad still works for movement/scrolling)

### Solution 2: Map INPUT_BTN_TOUCH to Useful Behavior (Beekeeb Toucan2 Approach)
Instead of filtering, map the touch event to something functional using `input-processor-behaviors`:

```devicetree
is_touching_processor: is_touching_processor {
    compatible = "zmk,input-processor-behaviors";
    #input-processor-cells = <0>;
    codes = <INPUT_BTN_TOUCH>;
    bindings = <&mo 4>;  // Activate Layer 4 when touching
};

&trackpad_listener {
    input-processors = <&is_touching_processor>,
                       <&zip_xy_scaler 100 100>,
                       <&zip_scroll_scaler 1 20>;
};
```

Then in your keymap, Layer 4 would contain mouse buttons:
- Bottom row: `&mkp MCLK`, `&mkp LCLK`, `&mkp RCLK`

**Pros:**
- Touch detection becomes useful (auto-activates mouse layer)
- No input events lost
- More elegant than filtering

**Cons:**
- Requires keymap changes
- Layer activation adds complexity

## Key Configuration Details

### Temporal Trackpad Config (temporal_trackpad.conf)
```properties
CONFIG_I2C=y
CONFIG_INPUT=y
CONFIG_INPUT_TPS43=y
CONFIG_INPUT_THREAD_STACK_SIZE=2048
```

### Dongle Config (temporal_rgbdongle.conf)
The dongle only needs:
```properties
CONFIG_INPUT=y
```

Why?
- `CONFIG_I2C` not needed (trackpad physically connected to peripheral, not dongle)
- `CONFIG_INPUT_TPS43` not needed (driver only runs on device with trackpad hardware)
- `CONFIG_INPUT` required (dongle runs the input listener and processors)
- `CONFIG_INPUT_THREAD_STACK_SIZE` optional (only if stack overflow errors occur)

### Device Dependencies
- `CONFIG_INPUT_TPS43` automatically enables `CONFIG_I2C` and `CONFIG_INPUT` as dependencies
- It's still best practice to explicitly set them for clarity and debugging

## Important Findings from Beekeeb Toucan2

Comparison with Beekeeb's implementation (also uses azoteq TPS43):

| Aspect | Our Approach | Beekeeb Toucan2 |
|--------|-------------|-----------------|
| **INPUT_BTN_TOUCH Handling** | Filter out (input-processor-key-filter) | Map to layer (input-processor-behaviors) |
| **idle-sleep** | Should be disabled | Explicitly disabled |
| **scroll-angle** | Default (~47°) | 30° (tighter) |
| **scroll-sensitivity** | 25% | 100% |
| **report-rate-lp2** | Not configured | 640ms (power optimized) |
| **hold-time** | 1200ms | 500ms |
| **Swipe Strategy** | All swipes enabled | Three-finger only |

### Critical Setting: idle-sleep
Beekeeb disables `idle-sleep` to prevent trackpad becoming unresponsive after ZMK idle. When enabled, trackpad takes ~300ms to wake up after idle timeout.

## Gesture Configuration Best Practices

### Why Disabling Gestures Didn't Help
Gestures are optional. The `INPUT_BTN_TOUCH` event is **mandatory** and happens regardless of gesture settings. This is why disabling all gestures still produced the click-drag effect.

### Scroll Behavior
Even with all gestures disabled, scrolling still works because it uses raw relative movement events:
- `INPUT_REL_WHEEL` (vertical)
- `INPUT_REL_HWHEEL` (horizontal)
- `INPUT_REL_MISC` (zoom, converted via `zip_zoom_to_wheel` processor)

These are independent of gesture detection and reported whenever movement is detected.

## Firmware Build & Flashing Considerations

### Required for Both Dongle and Peripheral
When rebuilding firmware:
1. Both dongle and peripheral need to be rebuilt
2. Flash both devices (dongle + right peripheral)
3. The `&trackpad_listener` runs on the dongle, so it needs the input processor configuration

### Dependency Chain
```
temporal_dongle (runs trackpad_listener)
    ↑ receives input events from
temporal_right (runs trackpad driver)
```

Both must be in sync for trackpad to work properly.

## Configuration Files Modified

1. **c:\Repo\zmk-config\config\t4corun\trackpad.dtsi**
   - Added `touch_filter` processor
   - Enabled it in `input-processors` chain

2. **c:\Repo\zmk-config\config\temporal_trackpad.conf**
   - Ensured `CONFIG_INPUT=y` is set

3. **c:\Repo\zmk-config\config\temporal_rgbdongle.conf**
   - Added `CONFIG_INPUT=y`

4. **c:\Repo\zmk-config\boards\shields\temporal\temporal_trackpad.overlay**
   - All trackpad gestures disabled for testing

## Testing Checklist

After implementing the fix:
- [ ] Mouse movement works without drag
- [ ] Scroll wheel still works (vertical/horizontal)
- [ ] Zoom still works (pinch gesture)
- [ ] Single-tap for left-click (if re-enabled)
- [ ] Two-finger tap for right-click (if re-enabled)
- [ ] No click-drag artifact

## Related Documentation

- ZMK Input Processors: `<input/processors.dtsi>`
- Azoteq TPS43 Driver: `C:\Repo\temp\zmk_driver_azoteq\dts\bindings\input\azoteq,tps43-common.yaml`
- Beekeeb Toucan2 Reference: `C:\Repo\temp\zmk-keyboard-toucan2\boards\shields\toucan\toucan.dtsi`

## Lessons Learned

1. **INPUT_BTN_TOUCH is not a gesture** — It's a raw touch detection event generated unconditionally by the driver
2. **Gesture disabling doesn't affect raw events** — Only affects high-level gesture recognition (tap, swipe, etc.)
3. **Input processors are powerful** — They allow fine-grained filtering and remapping of input events
4. **Splitting input layers is important** — Knowing where the driver runs (peripheral) vs where the listener runs (dongle) is critical
5. **Beekeeb's approach is elegant** — Mapping touch detection to layer activation is more useful than filtering
6. **Driver source inspection is necessary** — Device tree configuration alone cannot disable unconditional driver behavior

## Recommended Next Steps

1. Apply the `touch_filter` fix and test
2. If satisfied with filtering approach, keep current configuration
3. If you want richer functionality, consider adopting Beekeeb's `input-processor-behaviors` approach with Layer 4 mouse button mapping
4. Monitor for any UX issues with `idle-sleep` behavior
5. Consider customizing power-save settings (`report-rate-lp2`, `scroll-angle`) based on your preferences
