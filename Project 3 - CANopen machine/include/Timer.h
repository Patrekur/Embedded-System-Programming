#ifndef TIMER_H
#define TIMER_H
#include <arduino.h>

// Timer that counts seco

class Timer {
public:
<<<<<<< HEAD
    
=======
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc
    Timer() {

        interval = 50;

<<<<<<< HEAD
    }
=======
    }  
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc
    Timer(int freq);
    // initalize the the timer (timer 1)
    void init();
    // Start the timer
    void start();
    // Stop the timer
    void stop();
    // Check if finished
    bool isFinished();
    // Change the timeout value
    void changeTimeout(int freq);
    // Time increments on each output compare
    void incrTime();

private:

    // The timeout in seconds
    int interval = 0;
    // Value of the time in seconds
    int timer = 0;
    // boolean indicating timeout
    bool finished;

};

#endif