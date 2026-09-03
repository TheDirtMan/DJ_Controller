# Hardware Wrapper

Include `HardwareWrapper.h` to include all supported hardware classes at once:

```cpp
#include <HardwareWrapper.h>
```

This is optional. You can also include individual hardware classes if you only need specific types.

---
## Lights

### LED
___
Include the LED module (if not using `HardwareWrapper.h`):

```cpp
#include <Lights/LED.h>
```

#### Create an LED

```cpp
LED ledName(pinNumber, inverted);
```

`inverted` (optional, default: `false`): When `true`, LOW = on and HIGH = off

#### Initialize

Call in your `setup()` function:

```cpp
ledName.init();
```

#### Set State

`true` turns the LED on, `false` turns it off.

```cpp
ledName.setState(status);  // status is a boolean
```

#### Get State

```cpp
ledName.getState(direct);
```

`direct` is optional (default: `false`):
- `false`: Reads the stored state
- `true`: Reads the pin directly and updates stored state if mismatched

#### Set Brightness (PWM-capable pins only)

```cpp
ledName.setBrightness(brightness);  // brightness is a float 0.0-1.0
```

#### Get Brightness

```cpp
ledName.getBrightness(direct);
```

Returns a float `0.0-1.0`.

`direct` is optional (default: `false`):
- `false`: Reads the stored brightness
- `true`: Reads the pin directly and updates stored brightness if mismatched

> **Note**: The `LED` class is for single-color LEDs only. For multicolor LEDs, use the `RGBLED` class.

---

### RGBLED
___
Include the RGBLED module (if not using `HardwareWrapper.h`):

```cpp
#include <Lights/RGBLED.h>
```

#### Create an RGB LED

```cpp
RGBLED ledName(redPin, greenPin, bluePin, inverted, redBalance, greenBalance, blueBalance);
```

Parameters:
- `redPin`, `greenPin`, `bluePin`: Pin numbers for each channel
- `inverted` (optional, default: `false`): When `true`, LOW = on and HIGH = off
- `redBalance`, `greenBalance`, `blueBalance` (optional, default: `1.0` each): Color balance values as floats `0.0-1.0`

The class automatically detects PWM support:
- PWM-capable pins: Uses `analogWrite` for smooth brightness
- Non-PWM pins: Uses `digitalWrite`

#### Initialize

Call in your `setup()` function:

```cpp
ledName.init();
```

#### Set State

```cpp
ledName.setState(status);  // status is a boolean
```

#### Get State

```cpp
bool isOn = ledName.getState();
```

Returns `true` if on, `false` if off.

#### Set Overall Brightness

```cpp
ledName.setBrightness(brightness);  // brightness is a float 0.0-1.0
```

Controls all color channels simultaneously.

#### Get Overall Brightness

```cpp
float brightness = ledName.getBrightness();  // Returns float 0.0-1.0
```

#### Set Color

```cpp
ledName.setColor(red, green, blue);  // Each is a float 0.0-1.0
```

#### Get Color

```cpp
std::tuple<float, float, float> color = ledName.getColor();
float red = std::get<0>(color);
float green = std::get<1>(color);
float blue = std::get<2>(color);
```

Returns a tuple of three floats `0.0-1.0` representing the current color intensities.

#### Color Balance

Color balance values are applied automatically. For example, if your red channel is too bright, set `redBalance` to `0.8` to reduce its relative intensity.

---

## Buttons

### MomentaryButton
___
Include the MomentaryButton module (if not using `HardwareWrapper.h`):

```cpp
#include <Buttons/MomentaryButton.h>
```

#### Create a Button

```cpp
MomentaryButton buttonName(pinNumber, dbMillis, inverted);
```

Parameters:
- `pinNumber`: Pin number
- `dbMillis` (optional, default: `5`): Debounce time in milliseconds
- `inverted` (optional, default: `true`): When `true`, LOW = pressed (`true`) and HIGH = released (`false`)

#### Initialize

Call in your `setup()` function:

```cpp
buttonName.init();
```

#### Check if Pressed (Current State)

```cpp
buttonName.isDown(direct);
```

`direct` is optional (default: `false`):
- `false`: Reads debounced state
- `true`: Reads pin directly (bypasses debounce)

#### Check if Was Pressed (Edge Detection)

```cpp
bool pressed = buttonName.wasPressed();
```

Returns `true` for one update cycle after a press is detected (with debouncing applied).

#### Check if Was Released (Edge Detection)

```cpp
bool released = buttonName.wasReleased();
```

Returns `true` for one update cycle after a release is detected (with debouncing applied).

#### Update

When using `wasPressed()`, `wasReleased()`, or `isDown() // Without the direct option set to true`, call this in your `loop()` function:

```cpp
buttonName.update();
```
___
## Potentiometers

### Potentiometer

___

Include the Potentiometer module (if not using `HardwareWrapper.h`):

```cpp
#include <Potentiometers/Potentiometer.h>
```

#### Create a Potentiometer

```cpp
Potentiometer potName(pinNumber, alpha, resolution, rawMin, rawMax, inverted);
```

Parameters:

- `pinNumber`: Pin number
- `alpha` (optional, default: `0.3`): Filter strength as a float `0.0-1.0`
- `resolution` (optional, default: `12`): Analog read resolution in bits
- `rawMin` (optional, default: `0`): Minimum raw analog reading
- `rawMax` (optional, default: `4095`): Maximum raw analog reading
- `inverted` (optional, default: `false`): When `true`, the output is inverted

The potentiometer converts its raw analog reading into a float `0.0-1.0` based on `rawMin` and `rawMax`.

#### Initialize

Call in your `setup()` function:

```cpp
potName.init();
```

This sets the analog read resolution, disables analog averaging, reads the initial potentiometer position, and initializes the filtered output.

#### Update

Call in your `loop()` function:

```cpp
potName.update();
```

Reads the potentiometer and applies the configured filter before updating the useful output.

#### Get Position

```cpp
potName.getPosition(direct);
```

Returns a float `0.0-1.0`.

`direct` is optional (default: `false`):

- `false`: Reads the filtered position
- `true`: Reads the current raw position directly without filtering

#### Set Minimum

```cpp
potName.setMin(newMin);
```

Sets the minimum raw analog reading used for normalization.

#### Set Maximum

```cpp
potName.setMax(newMax);
```

Sets the maximum raw analog reading used for normalization.

#### Filtering

The `alpha` parameter controls how quickly the filtered output responds to changes:

- `0.0`: The filtered output does not change
- `1.0`: No filtering; the filtered output immediately matches the raw reading
- Values between `0.0-1.0`: Applies filtering between the previous and current readings

#### Inversion

When `inverted` is set to `true`, the normalized output is inverted:

- Normal: `0.0` → `1.0`
- Inverted: `1.0` → `0.0`

---