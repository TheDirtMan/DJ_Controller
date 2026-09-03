class ONOFFSwitch {

    private:

        int pinNumber;
        bool inverted;

        bool on;
        bool off;

        bool dbState;
        bool oldRaw;
        unsigned long dbTime;

        unsigned long currentTime;
        unsigned long dbEnd;


    public:

        ONOFFSwitch(int pin, unsigned long dbMillis = 5, bool inverted = true);

        bool getState(bool direct = false);
        bool wasSwitchedOn();
        bool wasSwitchedOff();

        void init();

        void update();


};