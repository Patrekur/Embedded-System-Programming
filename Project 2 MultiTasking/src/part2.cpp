#include <arduino.h>
#include <math.h>
#include "digital_out.h"
#include "digital_in.h"
#include "analog_in.h"
#include "analog_out.h"
#include "filter.h"

Digital_out digiout(5);
Digital_in  digiin(2);
Analog_in analogIn(0);
Analog_out analogOut(0.5);
IIR_Filter IIR(0.4); // input is alpha // 0.2 = 20% weight.  0 < alpha < 1
// low alpha means good smoothing but slow response, and vice versa.

float val = 0;
double IIRVal = 0;

double mapOneRangeToAnother(double sourceNumber, double fromA, double fromB, double toA, double toB, int decimalPrecision ) {
    // https://stackoverflow.com/questions/5731863/mapping-a-numeric-range-onto-another
    // We needed to map analog sensor value to its true potential range of 0-255
    // to be able to then use it to affect the duty cycle.
    // This custom function, unlike the map() function from the arduino library, returns double values. 
    double deltaA = fromB - fromA;
    double deltaB = toB - toA;
    double scale  = deltaB / deltaA;
    double negA   = -1 * fromA;
    double offset = (negA * scale) + toA;
    double finalNumber = (sourceNumber * scale) + offset;
    int calcScale = (int) pow(10, decimalPrecision);
    return (double) round(finalNumber * calcScale) / calcScale;
}


void setup() {


digiout.init();
digiin.init();
analogIn.init();
analogOut.init();
sei(); 
Serial.begin(9600); 
analogOut.changemode();
}

void loop() {
  val = analogIn.getval(); // read the analog sensor value
  IIRVal = IIR.exponentialFilter(val); // filter the signal 
  double mappedVal = (double) mapOneRangeToAnother(IIRVal, 9, 90, 0, 1, 3); // map the signal
  //Serial.print("mappedValll:      ");Serial.println(mappedVal);
  analogOut.dutyset(mappedVal); // set the duty cycle according to the signal of the sensor
  //delay(250);

}

// Interrupt routines

ISR(INT0_vect) {
  cli();
  Serial.println("Interrupt!!");
  delay(50);
  analogOut.changemode();

  sei();

}

ISR(TIMER1_COMPB_vect)
{

  digiout.set_lo();

}

ISR(TIMER1_COMPA_vect)
{

  digiout.set_hi();

}