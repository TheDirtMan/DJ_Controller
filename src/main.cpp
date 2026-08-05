#include <Arduino.h>
#include <HardwareWrapper.h>

LED statusLED(LED_BUILTIN);
MomentaryButton button(3);

void setup() {
  statusLED.init();
  button.init();
}

void loop() {
  statusLED.setState(button.wasPressed());
  button.update();
  delay(1);
}