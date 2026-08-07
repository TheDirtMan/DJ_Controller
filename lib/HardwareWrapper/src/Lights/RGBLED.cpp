#include <Lights/RGBLED.h>
#include <Arduino.h>
#include <tuple>

RGBLED::RGBLED(
    int redPinNumber, int greenPinNumber, int bluePinNumber,
    bool inverted,
    float redColorBalance, float greenColorBalance, float blueColorBalance) {
        this->redPinNumber = redPinNumber;
        this->greenPinNumber = greenPinNumber;
        this->bluePinNumber = bluePinNumber;

        status = inverted;

        redPWMPin = digitalPinHasPWM(redPinNumber);
        greenPWMPin = digitalPinHasPWM(greenPinNumber);
        bluePWMPin = digitalPinHasPWM(bluePinNumber);

        this->redColorBalance = constrain(redColorBalance, 0.0f, 1.0f);
        this->greenColorBalance = constrain(greenColorBalance, 0.0f, 1.0f);
        this->blueColorBalance = constrain(blueColorBalance, 0.0f, 1.0f);

        brightness = 1.0f;

        red = 1.0;
        green = 1.0;
        blue = 1.0;

        this->inverted = inverted;
    }


void RGBLED::updatePins() {
    float redValue = red;
    float greenValue = green;
    float blueValue = blue;

    if (inverted) {
        redValue = 1.0f - red;
        greenValue = 1.0f - green;
        blueValue = 1.0f - blue;
    }

    int redPWMValue = 255 * brightness * redValue * redColorBalance;
    int greenPWMValue = 255 * brightness * greenValue * greenColorBalance;
    int bluePWMValue = 255 * brightness * blueValue * blueColorBalance;

    if (status) {
        if (redPWMPin) {
            analogWrite(redPinNumber, redPWMValue);
        } else {
            digitalWriteFast(redPinNumber, redPWMValue >= 128 ? HIGH : LOW);
        }

        if (greenPWMPin) {
            analogWrite(greenPinNumber, greenPWMValue);
        } else {
            digitalWriteFast(greenPinNumber, greenPWMValue >= 128 ? HIGH : LOW);
        }

        if (bluePWMPin) {
            analogWrite(bluePinNumber, bluePWMValue);
        } else {
            digitalWriteFast(bluePinNumber, bluePWMValue >= 128 ? HIGH : LOW);
        }
    } else {
        if (redPWMPin) {
            analogWrite(redPinNumber, 0);
        } else {
            digitalWriteFast(redPinNumber, inverted ? HIGH : LOW);
        }

        if (greenPWMPin) {
            analogWrite(greenPinNumber, 0);
        } else {
            digitalWriteFast(greenPinNumber, inverted ? HIGH : LOW);
        }

        if (bluePWMPin) {
            analogWrite(bluePinNumber, 0);
        } else {
            digitalWriteFast(bluePinNumber, inverted ? HIGH : LOW);
        }
    }
}

bool RGBLED::getState() {
    return status;
}

void RGBLED::setState(bool state) {
    status = state;
    updatePins();
}

void RGBLED::init() {
    pinMode(redPinNumber, OUTPUT);
    pinMode(greenPinNumber, OUTPUT);
    pinMode(bluePinNumber, OUTPUT);
    updatePins();
}

void RGBLED::setBrightness(float brightness) {
    this->brightness = constrain(brightness, 0.0f, 1.0f);
    updatePins();
}

float RGBLED::getBrightness() {
    return brightness;
}

void RGBLED::setColor(float r, float g, float b) {
    red = constrain(r, 0.0f, 1.0f);
    green = constrain(g, 0.0f, 1.0f);
    blue = constrain(b, 0.0f, 1.0f);
    updatePins();
}

std::tuple<float, float, float> RGBLED::getColor() {
    return std::tuple<float, float, float>(red, green, blue);
}