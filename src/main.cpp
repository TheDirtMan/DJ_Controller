#include <Arduino.h>
#include <HardwareWrapper.h>

LED statusLED(LED_BUILTIN);

MomentaryButton onButton(3);
MomentaryButton offButton(4);

void setup() {
  statusLED.init();
  statusLED.setState(true);

  onButton.init();
  offButton.init();
}

void loop() {
  if (onButton.wasPressed()) {
    statusLED.setState(true);
  }
  if (offButton.wasPressed()) {
    statusLED.setState(false);
  }

  onButton.update();
  offButton.update();
  
  delay(1);
}