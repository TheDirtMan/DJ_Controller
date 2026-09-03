class Potentiometer {

    private:

        int pinNumber;
        int rawOutput;
        int filteredOutput;
        float usefulOutput;
        float filterAlpha;
        int rawMin;
        int rawMax;
        bool inverted;
        int resolution;

        float normalize(int value);


    public:

        Potentiometer(int pin, float alpha = 0.3, int res = 12, int min = 0, int max = 4095, bool inverted = false);

        float getPosition(bool direct = false);
        void setMin(int newMin);
        void setMax(int newMax);

        void init();
        void update();


};