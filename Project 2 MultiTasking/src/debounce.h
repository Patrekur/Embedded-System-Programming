#include <arduino.h>

// Debounce checks the state of the button every 10 ms, the button is considered pressed if 5 consecutive values are the same

class Debounce {
public:

    Debounce();
    void init();
    void reset();
    bool ispressed();
    void debounce(bool state);
    int getconsec();

private:
 
    int consecnr;

};