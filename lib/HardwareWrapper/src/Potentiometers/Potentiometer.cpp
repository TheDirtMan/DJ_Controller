#include "core_pins.h"
#include "pins_arduino.h"
#include <Arduino.h>
#include <Potentiometers/Potentiometer.h>

Potentiometer::Potentiometer(int pin, float alpha, int res, int min, int max, bool inverted) {
    pinNumber = pin;
    filterAlpha = alpha;
    resolution = res;
    rawMin = min;
    rawMax = max;
    this->inverted = inverted;

    filteredOutput = 0;
}


float Potentiometer::normalize(int value) {
    return (float)(value - rawMin) / (rawMax - rawMin);
}

float Potentiometer::getPosition(bool direct) {
    if (direct) {
        return normalize(rawOutput);
    } else {
        return usefulOutput;
    }
}

void Potentiometer::init() {
    analogReadResolution(resolution);
    analogReadAveraging(1); // disable averaging
    rawOutput = analogRead(pinNumber);
    usefulOutput = normalize(rawOutput);
    filteredOutput = rawOutput;
}

void Potentiometer::update() {
    rawOutput = analogRead(pinNumber);

    filteredOutput += (rawOutput - filteredOutput) * filterAlpha;

    usefulOutput = normalize(filteredOutput);
}

void Potentiometer::setMin(int newMin) {
    rawMin = newMin;
}

void Potentiometer::setMax(int newMax) {
    rawMax = newMax;
}