

// This main.cpp file contains our struggles with the debounce class 
// it does not function properly

#include <arduino.h>
#include "digital_out.h"
#include "digital_in.h"
#include "analog_in.h"
#include "analog_out.h"
#include "debounce.h"

Digital_out digiout(5);
Digital_in  digiin(2);
Analog_in analogIn(0);
Analog_out analogOut(0.5);
Debounce debon;

unsigned int val = 0;
double myResult = 0;

void setup() {

digiout.init();
digiin.init();
analogIn.init();
analogOut.init();
debon.init();
sei(); 
Serial.begin(9600);
analogOut.changemode();
}

double mapOneRangeToAnother(double sourceNumber, double fromA, double fromB, double toA, double toB, int decimalPrecision ) {
    double deltaA = fromB - fromA;
    double deltaB = toB - toA;
    double scale  = deltaB / deltaA;
    double negA   = -1 * fromA;
    double offset = (negA * scale) + toA;
    double finalNumber = (sourceNumber * scale) + offset;
    int calcScale = (int) pow(10, decimalPrecision);
    return (double) round(finalNumber * calcScale) / calcScale;
}

void loop() {
  
  if (debon.ispressed()) {

    analogOut.changemode();
    debon.reset();

  }

  Serial.println(debon.getconsec());

  //val = map(analogIn.getval(), 40, 200, 1, 255);
  val = analogIn.getval();
  myResult = (double) mapOneRangeToAnother(val, 10, 70, 0, 1, 1);
  //Serial.println(myResult);
  analogOut.dutyset(myResult);

}

// Interrupt routines

/*ISR(INT0_vect) {

  cli();

  Serial.println("Interrupt!!");

  analogOut.changemode();

  sei();

}

*/

ISR(TIMER1_COMPB_vect)
{

  digiout.set_lo();

}

ISR(TIMER1_COMPA_vect)
{

  digiout.set_hi();

}

ISR(TIMER2_COMPA_vect) {

  debon.debounce(digiin.is_lo());

}