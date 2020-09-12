#include "analog_out.h"

Analog_out::Analog_out(float duty) {

    dutyCycle = duty;
    cmprcount = 16000000/256 - 1;
    bool mode = false;

}

void Analog_out::init() {

    // Timer counter control registers set to 0
    TCCR1A = 0; 
    TCCR1B = 0;
    // Value of compare register B
    OCR1B = cmprcount*dutyCycle;
    // Value of compare register A
    OCR1A = cmprcount;
    // Clear timer on compare 
    TCCR1B |= (1 << WGM12); 
    // set interrupt on compare match A and B
    TIMSK1 |= (1 << OCIE1A) | (1 << OCIE0B);
    // set prescaler to 256 and start the timer
    TCCR1B |= (1 << CS12);

}

void Analog_out::dutyset(float duty) {

   // Serial.println((int)(duty*cmprcount));

    dutyCycle = duty;
    OCR1B = (int)(cmprcount*dutyCycle);

}

void Analog_out::changemode() {

if (mode == false) {

    // Counter changed to a low level to provide a high PWM frequency
    unsigned int cmprcount = 30;
    OCR1A = cmprcount;
    OCR1B = cmprcount * dutyCycle;
    TCNT1 = 0;
    mode = true;

}

else {

    unsigned int cmprcount = 16000000/256 - 1;
    OCR1A = cmprcount;
    OCR1B = cmprcount * dutyCycle;
    TCNT1 = 0;
    mode = false;

}


}