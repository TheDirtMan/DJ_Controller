#include <Buttons/MomentaryButton.h>
#include <Arduino.h>

MomentaryButton::MomentaryButton(int pin, unsigned long dbMillis, bool inverted) {
    pinNumber = pin;
    this->inverted = inverted;

    dbState = false;
    dbTime = dbMillis;
    oldRaw = false;

    pressed = false;
    released = false;

    currentTime = 0;
    dbEnd = 0;
}

void MomentaryButton::init() {
    pinMode(pinNumber, INPUT_PULLUP);
}

bool MomentaryButton::isDown(bool direct) {
    if (direct) {
        return inverted ? !digitalReadFast(pinNumber) : digitalReadFast(pinNumber);
    }
    return dbState;
}

void MomentaryButton::update() {
    currentTime = millis();

    pressed = false;
    released = false;

    bool isDown = this->isDown(true);

    if (isDown != oldRaw) {
        dbEnd = currentTime + dbTime;
    }

    if (currentTime >= dbEnd) {
        if (isDown != dbState) {
            dbState = isDown;

            if (dbState) {
                pressed = true;
            } else {
                released = true;
            }
        }
    }

    oldRaw = isDown;
}

bool MomentaryButton::wasPressed() {
    return pressed;
}

bool MomentaryButton::wasReleased() {
    return released;
}