#include <tuple>

class RGBLED {

    private:

        bool status;

        bool redPWMPin;
        bool greenPWMPin;
        bool bluePWMPin;

        int redPinNumber;
        int greenPinNumber;
        int bluePinNumber;

        float redColorBalance;
        float greenColorBalance;
        float blueColorBalance;

        float brightness;

        float red;
        float blue;
        float green;

        bool inverted;

        void updatePins();

    public:

        RGBLED(
            int redPinNumber, int greenPinNumber, int bluePinNumber,
            bool inverted = false,
            float redColorBalance = 1.0f, float greenColorBalance = 1.0f, float blueColorBalance = 1.0f
        );

        bool getState();
        void setState(bool state);
        void init();

        void setBrightness(float brightness);
        float getBrightness();

        void setColor(float r, float g, float b);
        std::tuple<float, float, float> getColor();

};