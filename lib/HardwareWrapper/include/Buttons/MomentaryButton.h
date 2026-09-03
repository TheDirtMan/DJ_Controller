class MomentaryButton {

    private:

        int pinNumber;
        bool inverted;

        bool pressed;
        bool released;

        bool dbState;
        bool oldRaw;
        unsigned long dbTime;

        unsigned long currentTime;
        unsigned long dbEnd;

    public:


        MomentaryButton(int pin, unsigned long dbMillis = 5, bool inverted = true);

        bool isDown(bool direct = false);
        bool wasPressed();
        bool wasReleased();

        void init();

        void update();

};