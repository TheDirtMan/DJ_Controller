#include <Arduino.h>
#include <HardwareWrapper.h>

LED statusLED(LED_BUILTIN);

void setup() {
  statusLED.init();
  statusLED.setState(true);
}

void loop() {
  float brightness = ((sin(millis() / 1000.0f) + 1.0f) / 2.0f) + 0.01;

  statusLED.setBrightness(brightness);
  
  delay(1);
}