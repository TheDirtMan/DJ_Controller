# Hardware Wrapper

Include `HardwareWrapper.h` to include all supported hardware classes at once.

```cpp
#include <HardwareWrapper.h>
```

This is completely optional. You can also include each hardware class individually if you only need specific hardware types.

---

# Hardware and Features

## LED

Create an LED device with:

```cpp
LED ledName(pinNumber);
```
___
Initialize the LED's pin inside your `setup()` function:

```cpp
ledName.init();
```
___
Set the state of an LED with:

```cpp
ledName.setState(status);
```

`status` is a boolean value. `true` turns the LED on, and `false` turns it off.
___
Get the current state of an LED with:

```cpp
ledName.getState(direct);
```

`direct` controls whether the pin is read directly.

* `false` reads the stored status.
* `true` reads the pin state directly, and updates the stored status if unmatched.

The default value is `false`.
___
If your LED is connected to a PWM-capable pin, you can control its brightness.
___
Set the brightness of an LED with

```c++
ledName.setBrightness(brightness);
```

Brightness is a float 0.0-1.0.
___
Read the brightness of an LED with

```c++
ledName.getBrightness(direct);
```

This returns a float 0.0-1.0.

`direct` controls whether the pin is read directly.

* `false` reads the stored brightness.
* `true` reads the pin state directly, and updates the stored brightness if unmatched.

Default state is `false`.

___
LED devices with multiple colors are not currently supported.

## MomentaryButton

Create a momentary button with:

```cpp
MomentaryButton buttonName(pinNumber, dbMillis, inverted);
```

`dbMillis` controls the debounce time in milliseconds. If not provided, default value is `25`.

`inverted` controls the button's logic. If not provided, default value is `true`.

When inverted is enabled:

* `LOW` = pressed (`true`)
* `HIGH` = released (`false`)
___
Initialize the button's pin inside your `setup()` function:

```cpp
buttonName.init();
```
___
Read the current state of a button with:

```cpp
buttonName.isDown(direct);
```

`direct` controls whether the debounce system is ignored.

* `false` reads the debounced state.
* `true` reads the pin state directly.

Default state is `false`.
___
Check if a button was pressed with:

```cpp
buttonName.wasPressed();
```

Returns `true` for one update cycle after the button is pressed.

Debouncing is applied.
___
Check if a button was released with:

```cpp
buttonName.wasReleased();
```

Returns `true` for one update cycle after the button is released.

Debouncing is applied.
___
If using either `wasPressed()` or `wasReleased()`, you must include the following in your `loop()` function.

```c++
buttonName.update();
```
