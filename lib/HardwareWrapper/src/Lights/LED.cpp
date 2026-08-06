#include <Lights/LED.h>
#include <Arduino.h>

LED::LED(int pin) {
    pinNumber = pin;
    status = false;
    brightness = 255;

    PWMPin = digitalPinHasPWM(pinNumber);
}


bool LED::getState(bool direct) {
    if (direct) {
        status = digitalReadFast(pinNumber) == HIGH;
    }
    return status;
}

void LED::setState(bool state) {
    status = state;
    if (state) {
        if (PWMPin) {
            analogWrite(pinNumber, brightness);
        } else {
            digitalWriteFast(pinNumber, brightness > 0);
        }
    } else {
        digitalWriteFast(pinNumber, 0);
    }
}

void LED::init() {
    pinMode(pinNumber, OUTPUT);
    setState(status);
}


float LED::getBrightness(bool direct) {
    if (direct) {
        brightness = analogRead(pinNumber)/255.0;
    }
    return brightness/255.0f;
}

void LED::setBrightness(float newBrightness) {
    brightness = constrain(newBrightness, 0.0f, 1.0f)*255;
    setState(status);
}