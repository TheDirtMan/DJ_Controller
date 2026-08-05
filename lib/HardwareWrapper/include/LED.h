class LED {

    private:

        bool status;
        int pinNumber;

    public:

        LED(int pin);

        bool getState();
        void setState(bool state);
        void init();


};