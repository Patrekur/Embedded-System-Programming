#include <arduino.h> 

class Analog_out {
public:
    
    Analog_out(float duty);
    void init();
    void dutyset(float duty);

private:

    // Scales the cmprcount value down for a shorter duty cycle
    float dutyCycle;
    // PWM operating at 1 Hz given 1024 prescaler
    const int cmprcount = 16000000/1024 - 1;

};