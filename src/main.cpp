#include <Arduino.h>

/*
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
*/

#include <MIDIWrapper.h>

MIDINote testSignal(60, 127, 1);

void loop() {
  testSignal.setState(true);
  testSignal.update();
  delay(1000);
  testSignal.setState(false);
  testSignal.update();
  delay(1000);
}