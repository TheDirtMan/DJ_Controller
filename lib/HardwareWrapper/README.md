# Hardware Wrapper

Include `HardwareWrapper.h` to automatically include all supported hardware types.

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

Initialize the LED's pin inside your `setup()` function:

```cpp
ledName.init();
```

Set the state of an LED with:

```cpp
ledName.setStatus(true);
```

Get the current state of an LED with:

```cpp
ledName.getStatus();
```

This returns a boolean representing the state last set by the device. It does **not** read the actual state of the pin.

LED devices with multiple colors are not currently supported.

---

## MomentaryButton

Create a momentary button with:

```cpp
MomentaryButton buttonName(pinNumber, dbMillis, inverted);
```

`dbMillis` controls the debounce time in milliseconds. If not provided, it defaults to `25`.

`inverted` controls the button's logic. If not provided, it defaults to `true`.

When inverted is enabled:

* `LOW` = pressed (`true`)
* `HIGH` = released (`false`)

Initialize the button's pin inside your `setup()` function:

```cpp
buttonName.init();
```

### Reading Button State

Read the current state of a button with:

```cpp
buttonName.isDown(direct);
```

`direct` controls whether the debounce system is ignored.

* `false` reads the debounced state.
* `true` reads the pin state directly.

### Detecting Button Presses

Check if a button was pressed with:

```cpp
buttonName.wasPressed();
```

Returns `true` for one update cycle after the button is pressed.

Debouncing is applied.

### Detecting Button Releases

Check if a button was released with:

```cpp
buttonName.wasReleased();
```

Returns `true` for one update cycle after the button is released.

Debouncing is applied.
