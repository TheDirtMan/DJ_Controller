Include HardwareWrapper.h to automatically include all hardware types.
It is completely optional, you can just include each hardware class as you need it.

# Hardware and Features

### LED
Define an LED device with
```c++
LED ledName(pinNumber);
```

Initialize an LED device's pin with
```c++
ledName.init();
```
inside your `setup()` function.

Set the state of an LED device with
```c++
ledName.setStatus(true);
```

Get the state of an LED device with
```c++
ledName.getStatus(); // Returns a boolean. Does not check the actual state of the pin.
```

LED devices with multiple colors are not supported (yet).


### MomentaryButton
Define a momentary button with
```c++
MomentaryButton buttonName(pinNumber, dbMillis, inverted);
```
`dbMillis` is optional, and if not supplied defaults to 25.
`inverted` is option, and if not supplied defaults to true.
`inverted` makes LOW = true and HIGH = false.

Initialize a button's pin with
```c++
buttonName.init();
```
inside your `setup()` function.

Read a buttons state with
```c++
buttonName.isDown(direct);
```
the `direct` boolean lets you read the pinstate directly rather if you want to ignore debounce.

Button press
```c++
buttonName.wasPressed();
```
Returns true for an instant after the button was pressed. Debounce applied.

Button release
```c++
buttonName.wasReleased();
```
Returns true for an instant after the button was released. Debounce applied.