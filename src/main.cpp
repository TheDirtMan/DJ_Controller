#include "pins_arduino.h"
#include <Arduino.h>
#include <HardwareWrapper.h>

Potentiometer knob(A0);
LED builtin(LED_BUILTIN);

void setup() {
  knob.init();
  builtin.init();
  builtin.setState(true);
}

void loop() {
  knob.update();
  builtin.setBrightness(knob.getPosition());
  delay(1);
}