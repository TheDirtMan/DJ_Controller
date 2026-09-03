#include <Switches/ONOFFSwitch.h>
#include <Arduino.h>

ONOFFSwitch::ONOFFSwitch(int pin, long unsigned dbMillis, bool inverted) {
    pinNumber = pin;
    this->inverted = inverted;

    dbState = false;
    dbTime = dbMillis;
    oldRaw = false;

    on = false;
    off = false;

    currentTime = 0;
    dbEnd = 0;
}

void ONOFFSwitch::init() {
    pinMode(pinNumber, INPUT_PULLUP);
}

bool ONOFFSwitch::getState(bool direct) {
    if (direct) {
        return inverted ? !digitalRead(pinNumber) : digitalRead(pinNumber);
    }
    return dbState;
}

void ONOFFSwitch::update() {
    currentTime = millis();

    on = false;
    off = false;

    bool getState = this->getState(true);

    if (getState != oldRaw) {
        dbEnd = currentTime + dbTime;
    }

    if (currentTime >= dbEnd) {
        if (getState != dbState) {
            dbState = getState;

            if (dbState) {
                on = true;
            } else {
                off = true;
            }
        }
    }

    oldRaw = getState;
}

bool ONOFFSwitch::wasSwitchedOn() {
    return on;
}

bool ONOFFSwitch::wasSwitchedOff() {
    return off;
}