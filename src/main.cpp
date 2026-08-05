#include <Arduino.h>
#include <HardwareWrapper.h>

LED statusLED(LED_BUILTIN);

void setup() {
  statusLED.init();
}

void loop() {
  statusLED.setState(!statusLED.getState());
  delay(1000);
}