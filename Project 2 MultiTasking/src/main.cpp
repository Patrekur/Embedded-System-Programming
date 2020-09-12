#include <arduino.h>
#include "digital_out.h"
#include "digital_in.h"
#include "analog_in.h"
#include "analog_out.h"

Digital_out digiout(5); // pin 13 LEDbuiltin
Digital_in  digiin(4);  // pin 12 Port B
Analog_in analogIn(0); // Analog pin A0 portC?
Analog_out analogOut(0.5); // duty cycle = 50%
int val = 0;

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
  Serial.println(digiin.is_hi());
  
  val = map(160, 200, 1, 255);
  Serial.println(val);
  delay(500);
  // analogOut.dutyset(val/(float)255);
  

}

// Interrupt routines

ISR(TIMER1_COMPB_vect)
{

PORTB &= ~(1 << 5);

}

ISR(TIMER1_COMPA_vect)
{

PORTB |= (1 << 5);

}