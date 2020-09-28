#include "states.h"

Context *context;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Goes into initialization state
  context = new Context(new Initialize);
  //tim.init();
  //ledStatus.init();
  //tim.start();
}

// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)


void loop() {
  delay(100);

  
  // Housekeeping accepts serial commands:
  // 1 - Reset
  // 2 - Configure
  // 3 - Set operatonal
  // 4 - Set pre-operational
  // 5 - Clear fault

  context->housekeeping(); 
  context->dostuff();
  
}

// Timer 1 used for PWM, used by analog out class
ISR(TIMER1_COMPB_vect)
 {

  context->outLo();

 }

ISR(TIMER1_COMPA_vect)
  {

  context->outHi();

 }

//Status light interrupt
ISR(TIMER2_COMPA_vect) {

context->incrTime();

if (context->isFinished()) {

   context->toggleStatus();

}

}
