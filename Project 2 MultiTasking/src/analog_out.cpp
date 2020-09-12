#include "analog_out.h"

Analog_out::Analog_out(float duty) {

    dutyCycle = duty;

}

void Analog_out::init() {

    // Timer counter control registers set to 0
    TCCR1A = 0; 
    TCCR1B = 0;
    // An arbitrary value to create a uneven on/off time
    OCR1B = cmprcount*dutyCycle;
    // With a prescaler of 1024 the corresponding value in the output compare register for 1 second
    // Duty cycle is then: (15625-3200)/15625 = 79,5 %
    OCR1A = cmprcount;
    // Clear timer on compare 
    TCCR1B |= (1 << WGM12); 
    // set interrupt on compare match A and B
    TIMSK1 |= (1 << OCIE1A) | (1 << OCIE0B);
    // set prescaler to 1024 and start the timer
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // Global interrupts enabled

}

void Analog_out::dutyset(float duty) {

    Serial.println((int)(duty*cmprcount));

    dutyCycle = duty;
    OCR1B = (int)(cmprcount*dutyCycle);



}