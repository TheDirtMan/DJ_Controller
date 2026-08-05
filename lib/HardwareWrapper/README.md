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