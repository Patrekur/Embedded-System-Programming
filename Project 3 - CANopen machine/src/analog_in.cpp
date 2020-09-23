#include "analog_in.h"

    Analog_in::Analog_in(int pin) {

        pinMask = (0 << pin);

    }

    void Analog_in::init() {

        //Setting A0 as input
        DDRC &= pinMask;
        // Left justified data representation with AVCC as reference
        // and ADC0 as input
        ADMUX = 0b01100000;
        // Prescaler set to maximum 128 - clock rate at 125 kHz
        ADCSRA = 0b10000111;

    }

    int Analog_in::getval() {

         // ADC conversion started
        ADCSRA = ADCSRA | (1 << ADSC);
        // Wait while conversion is in progress
        while(ADCSRA & (1 << ADSC));
  
        return ADCH;

    }