#include <Arduino.h>
#include <HardwareWrapper.h>

LED statusLED(LED_BUILTIN);
ONOFFSwitch toggleSwitch(2);
ONOFFSwitch direction(3);
MomentaryButton adjustor(4);

float brightness = 0.5;

void setup() {
  statusLED.init();
  toggleSwitch.init();
  direction.init();
  adjustor.init();
}

void loop() {
  statusLED.setState(toggleSwitch.getState());
  if (adjustor.isDown()) {
    if (direction.getState()) {
      if (brightness < 1.00) {
        brightness += 0.01;
      }
    } else {
      if (brightness > 0.01) {
        brightness -= 0.01
      }
    }
  }
  statusLED.setBrightness(brightness);
  toggleSwitch.update();
  direction.update();
  adjustor.update();
  delay(1);
}