#include <Arduino.h>
#include <HardwareWrapper.h>

LED statusLED(LED_BUILTIN);
MomentaryButton button(3);

void setup() {
  statusLED.init();
  button.init();
}

void loop() {
  if (button.wasPressed()) {
    statusLED.setState(!statusLED.getState());
  }
  button.update();
  delay(1);
}