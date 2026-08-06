class LED {

    private:

        bool status;
        int pinNumber;

        int brightness;

        bool PWMPin;

    public:

        LED(int pin);

        bool getState(bool direct = false);
        void setState(bool state);
        void init();

        void setBrightness(float brightness);
        float getBrightness(bool direct = false);


};