#include "digital_in.h"


Digital_in::Digital_in(int pin) {

    pinMask = (1 << pin);

}

void Digital_in::init() {

    DDRD &= ~pinMask; 
     // Input pullup
    PORTD |= pinMask;

    // Set to trigger on rising edge
    EICRA |= (1 << ISC10);
    // Turn on interrupt 
    EIMSK |= (1 << INT0);

}


bool Digital_in::is_hi() {

    return PIND & pinMask;

}

bool Digital_in::is_lo() {

    bool isOpen = 0;
    isOpen = PIND & pinMask;

    return !is_hi();

}
