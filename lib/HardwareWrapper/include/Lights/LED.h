class LED {

    private:

        bool status;
        int pinNumber;

        int brightness;

        bool inverted;

        bool PWMPin;

    public:

        LED(int pin, bool inverted = false);

        bool getState(bool direct = false);
        void setState(bool state);
        void init();

        void setBrightness(float brightness);
        float getBrightness(bool direct = false);


};