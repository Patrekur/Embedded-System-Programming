#include <arduino.h> 

class Analog_out {
public:
    // Constructor
    Analog_out(float duty);
    void init();
    // Duty cycle set
    void dutyset(float duty);
    // Low/high frequency mode -- 1 Hz / 625 Hz
    void changemode();

private:
    // bool to keep track of current mode -- false = 1Hz -- true = 625 Hz
    bool mode;
    // Scales the cmprcount value down for a shorter duty cycle. The value for compare register B
    float dutyCycle;
    // PWM operating at 1 Hz given 1024 prescaler
    unsigned int cmprcount;

};