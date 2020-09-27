#include <arduino.h> 

class Analog_in {
public:
<<<<<<< HEAD
    
    Analog_in() {

        pinMask = (0 << 0);

    }
=======
    Analog_in() {

    pinMask = (0 << 0);

    }   
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc
    Analog_in(int pin);
    void init();
    int getval();

private:

    uint8_t pinMask;

};