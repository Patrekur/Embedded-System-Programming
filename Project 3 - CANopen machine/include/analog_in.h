#include <arduino.h> 

class Analog_in {
public:
    Analog_in() {

    pinMask = (0 << 0);

    }   
    Analog_in(int pin);
    void init();
    int getval();

private:

    uint8_t pinMask;

};