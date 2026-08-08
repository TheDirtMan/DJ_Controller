#include <Lights/LED.h>
#include <Arduino.h>

LED::LED(int pin, bool inverted) {
    pinNumber = pin;
    status = inverted;
    brightness = 255;

    this->inverted = inverted;

    PWMPin = digitalPinHasPWM(pinNumber);
}


bool LED::getState(bool direct) {
    if (direct) {
        if (inverted) {
            status = digitalReadFast(pinNumber) == LOW;
        } else {
            status = digitalReadFast(pinNumber) == HIGH;
        }
    }
    return status;
}

void LED::setState(bool state) {
    status = inverted ? !state : state;
    if (state) {
        if (PWMPin) {
            analogWrite(pinNumber, brightness);
        } else {
            digitalWrite(pinNumber, brightness > 0);
        }
    } else {
        if (PWMPin) {
            analogWrite(pinNumber, 0);
        } else {
            digitalWrite(pinNumber, LOW);
        }
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
    if (inverted) {
        brightness = (1.0f-constrain(newBrightness, 0.0f, 1.0f))*255;
    } else {
        brightness = constrain(newBrightness, 0.0f, 1.0f)*255;
    }
    setState(status);
}