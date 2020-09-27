#include "timer.h"

    Timer::Timer(int freq) {

        // Set timeout period
        interval = 50/freq;

    }

    void Timer::init() {

        // Timer/counter control register set to 0
        TCCR2B = 0;
        // Value of compare register B
        // clock/1024*100 - 1 = 155
        // Compare at 155 counts for a time interval of 10 ms 
        OCR2A = 155;
        // Clear timer on compare 
        TCCR2B |= (1 << WGM22); 
        // set interrupt on compare match A
        TIMSK2 |= (1 << OCIE2A);
        // set prescaler to 1024 and start the timer
        TCCR2B |= (1 << CS22) | (1 << CS21) | (1 < CS20);

    }
    
    void Timer::start() {

        // set prescaler to 1024 and start the timer
        TCCR2B |= (1 << CS22) | (1 << CS21) | (1 < CS20);

    }

    void Timer::stop() {

        // Timer2 clock source disabled
        TCCR2B &= ~(1 << CS22);
        TCCR2B &= ~(1 << CS21);
        TCCR2B &= ~(1 < CS20);

    }

    bool Timer::isFinished() {

        if (finished) {

            finished = false;
            return true;
        }

        else {

            return false;

        }

    }

    void Timer::changeTimeout(int freq) {

        interval = 50/freq;

    }

    void Timer::incrTime() {

        timer++;

        if (timer == interval) {

            finished = true;
            timer = 0;

        }

    }