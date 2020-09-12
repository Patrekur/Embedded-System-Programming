#include "digital_in.h"


Digital_in::Digital_in(int pin) {

    pinMask = (1 << pin);

}

void Digital_in::init() {

    DDRB &= ~pinMask; 

    // Input pullup
    PORTB |= pinMask;

}


bool Digital_in::is_hi() {

    bool isClosed = 0;
    isClosed = PINB & pinMask;

    return isClosed;

}

bool Digital_in::is_lo() {

    bool isOpen = 0;
    isOpen = PINB & pinMask;

    return isOpen;

}
