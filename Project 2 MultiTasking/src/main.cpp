#include <arduino.h>
#include <math.h>
#include "digital_out.h"
#include "digital_in.h"
#include "analog_in.h"
#include "analog_out.h"

Digital_out digiout(5);
Digital_in  digiin(2);
Analog_in analogIn(0);
Analog_out analogOut(0.5);
float val = 0;

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
}

void loop() {


  
  
  val = analogIn.getval();
  Serial.print("val fyrir:    ");Serial.println(val);

  val = map(val, 0, 400, 1, 255);
  


  Serial.print("mapped val:           ");Serial.println(val);
  
  val = val/(float)255;
  Serial.print("val/255: between 0-1: ");Serial.println(val);
  double myResult = (double) mapOneRangeToAnother(val, 0.15, 0.6, 0, 1, 3);
  Serial.print("mapOneRangeToAnother: ");Serial.println(myResult);
  //val = map(val,0.25,0.55,0,1);
  //Serial.print("map(val,0.25,0.55,0,1): ");Serial.println(val);

  analogOut.dutyset(myResult);
  // analogOut.dutyset(val/(float)255);
  delay(250);

}

// Interrupt routines

ISR(INT0_vect) {

  Serial.println("Interrupt!!");
  delay(50);
  analogOut.changemode();

  // The ISR runs while the button is held
  while(digiin.is_lo()) {}


}

ISR(TIMER1_COMPB_vect)
{

  digiout.set_lo();

}

ISR(TIMER1_COMPA_vect)
{

  digiout.set_hi();

}