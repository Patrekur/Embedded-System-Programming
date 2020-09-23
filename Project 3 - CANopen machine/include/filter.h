#include <arduino.h> 

class IIR_Filter {
public:
    // Constructor
    IIR_Filter(float weight);
    void init();    // not sure if necessary in this case
    double exponentialFilter(float sensorPin); // the filter function
    double mapping(double sourceNumber, double fromA, double fromB, double toA, double toB, int decimalPrecision );

private:
    float alpha; // the functionn weight
    float raw;  // newest data to be filtered
    float filteredData; 

    double deltaA;
    double deltaB;
    double scale;
    double negA;
    double offset;
    double finalNumber;
    int calcScale;
    double ratio;
};