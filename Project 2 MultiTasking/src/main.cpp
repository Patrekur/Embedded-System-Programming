#include <arduino.h>
#include "digital_out.h"
#include "digital_in.h"
#include "analog_in.h"
#include "analog_out.h"

Digital_out digiout(5);
Digital_in  digiin(2);
Analog_in analogIn(0);
//Analog_out analogOut(0.5);
int val = 0;

void setup() {

digiout.init();
digiin.init();
analogIn.init();
//analogOut.init();
sei(); 
Serial.begin(9600);
analogOut.changemode();
}

void loop() {

  //val = analogIn.getval();
  
  //Serial.println(val);
  
  //analogOut.dutyset(val/(float)255);

}

// Interrupt routines

ISR(INT0_vect) {

Serial.println("Interrupt!!");

digiout.toggle();

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