#include <Lights/LED.h>
#include <Arduino.h>

LED::LED(int pin) {
    pinNumber = pin;
    status = false;
}


bool LED::getState() {
    return status;
}

void LED::setState(bool state) {
    status = state;
    digitalWriteFast(pinNumber, status ? HIGH : LOW);
}

void LED::init() {
    pinMode(pinNumber, OUTPUT);
}