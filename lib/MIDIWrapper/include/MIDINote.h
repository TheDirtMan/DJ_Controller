#pragma once

#include <Arduino.h>


class MIDINote {

    private:

        uint8_t note;
        uint8_t velocity;
        uint8_t channel;

        bool state;
        bool lastState;


        
    public:

        MIDINote(uint8_t note, uint8_t velocity = 127, uint8_t channel = 1);

        void setNote(uint8_t note);
        void setVelocity(uint8_t velocity);
        void setChannel(uint8_t channel);
        void setState(bool state);

        uint8_t getNote() const;
        uint8_t getVelocity() const;
        uint8_t getChannel() const;
        bool getState() const;

        bool hasChanged() const;
        void update();

};
