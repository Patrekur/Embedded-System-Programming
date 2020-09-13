#include "debounce.h"

    Debounce::Debounce() {


    }

    void Debounce::init() {

        // Timer/counter control register set to 0
        TCCR2B = 0;
        // Value of compare register B
        OCR2A = 77;
        // Clear timer on compare 
        TCCR2B |= (1 << WGM22); 
        // set interrupt on compare match A and B
        TIMSK2 |= (1 << OCIE2A);
        // set prescaler to 1024 and start the timer
        TCCR2B |= (1 << CS22) | (1 << CS21) | (1 < CS20);

    }

    void Debounce::reset() {

        consecnr = 0;

    }

    bool Debounce::ispressed() {
        
        return (consecnr > 5); // when consecnr has incremented up over 5 then return true
    }


    void Debounce::debounce(bool state) {

        if (state == true) {

            consecnr = consecnr + 1; // if state is unchanged then increment consecnr

        }

        else {

            consecnr = 0;

        }


    }

    int Debounce::getconsec() {

        return consecnr;

    }