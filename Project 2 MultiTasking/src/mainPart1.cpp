#include <arduino.h>
#include "digital_out.h"
#include "digital_in.h"
#include "analog_in.h"
#include "analog_out.h"

Digital_out digiout(5);
Digital_in  digiin(2);
Analog_in analogIn(0);
Analog_out analogOut(0.5);
unsigned int val = 0;


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

  //val = map(analogIn.getval(), 40, 200, 1, 255);
  double val = analogIn.getval();
  Serial.print("unmapped: ");Serial.println(val);

  val = (double) mapOneRangeToAnother(val, 9, 60, 0, 1, 3);
  Serial.println(val);
  analogOut.dutyset(val);

}

// Interrupt routines

ISR(INT0_vect) {

  cli();

  Serial.println("Interrupt!!");

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