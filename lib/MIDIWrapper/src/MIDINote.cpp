#include <MIDINote.h>

MIDINote::MIDINote(uint8_t note, uint8_t velocity, uint8_t channel) {
    this->note = note;
    this->velocity = velocity;
    this->channel = channel;

    state = false;
    lastState = false;
}

void MIDINote::setNote(uint8_t note) {
    this->note = note;
}

void MIDINote::setVelocity(uint8_t velocity) {
    this->velocity = velocity;
}

void MIDINote::setChannel(uint8_t channel) {
    this->channel = channel;
}

void MIDINote::setState(bool state) {
    this->state = state;
}

uint8_t MIDINote::getNote() const {
    return note;
}

uint8_t MIDINote::getVelocity() const {
    return velocity;
}

uint8_t MIDINote::getChannel() const {
    return channel;
}

bool MIDINote::getState() const {
    return state;
}

bool MIDINote::hasChanged() const {
    return state != lastState;
}

void MIDINote::update() {
    if (!hasChanged()) {
        return;
    }

    if (state) {
        usbMIDI.sendNoteOn(note, velocity, channel);
    } else {
        usbMIDI.sendNoteOff(note, 0, channel);
    }

    lastState = state;
}