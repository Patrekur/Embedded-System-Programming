#include <arduino.h>
#include "analog_in.h"
#include "analog_out.h"
#include "digital_out.h"
#include "context.h"
#include "states.h"
#include "filter.h"
#include "timer.h"

Digital_out ledOut(4);
Digital_out ledStatus(5);
Analog_in input(0);
Analog_out output(0.5);
Timer tim(1);

Context *context;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Goes into initialization state
  context = new Context(new Initialize);
  tim.init();
  ledStatus.init();
  tim.start();
}

// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)


void loop() {
  // put your main code here, to run repeatedly:


  // Henda þessu inn í State sem housekeeping?
  if(Serial.available())
  {
    switch (Serial.read())
    {
      // State 
      case '1':
        context->Reset();
        break;
      case '2':
        context->Configure();
        break;
    }
  }
}

// Timer 1 used for PWM, used by analog out class
ISR(TIMER1_COMPB_vect)
{

  ledOut.set_lo();

}

ISR(TIMER1_COMPA_vect)
{

  ledOut.set_hi();

}

// Status light interrupt
ISR(TIMER2_COMPA_vect) {

tim.incrTime();

if (tim.isFinished()) {

  ledStatus.toggle();

}

}