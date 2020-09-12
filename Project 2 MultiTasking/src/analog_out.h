#include <arduino.h> 

class Analog_out {
public:
    
    Analog_out(float duty);
    void init();
    void dutyset(float duty);
    void changemode();

private:

    bool mode;
    // Scales the cmprcount value down for a shorter duty cycle. The value for compare register B
    float dutyCycle;
    // Compare register value for compareA
    unsigned int cmprcount;

};