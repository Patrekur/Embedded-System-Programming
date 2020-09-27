<<<<<<< HEAD
=======

>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc
#include "states.h"

Context *context;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Goes into initialization state
  context = new Context(new Initialize);
<<<<<<< HEAD
  context->init();
  //tim.init();
  //ledStatus.init();
  //tim.start();
=======
  // tim.init();
  // ledStatus.init();
  // tim.start();
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc
}

// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)


void loop() {
  // put your main code here, to run repeatedly:

<<<<<<< HEAD
  delay(500);

  context->toggleStatus();
=======
  //delay(500);
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc

  //context->toggleStatus();  
  // Henda þessu inn í State sem housekeeping?
  /*
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
      case '3':
        context->setOp();
        break;
      case '4':
        context->setPreOp();
        break;
    }
  }
  */
}

// Timer 1 used for PWM, used by analog out class
// ISR(TIMER1_COMPB_vect)
// {

<<<<<<< HEAD
  //ledOut.set_lo();
=======
//   ledOut.set_lo();
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc

// }

// ISR(TIMER1_COMPA_vect)
// {

<<<<<<< HEAD
  //ledOut.set_hi();
=======
//   ledOut.set_hi();
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc

// }

// // Status light interrupt
// ISR(TIMER2_COMPA_vect) {

<<<<<<< HEAD
//context->incrTime();
/*
if (tim.isFinished()) {

  //ledStatus.toggle();

}
*/
}
=======
// tim.incrTime();

// if (tim.isFinished()) {

//   ledStatus.toggle();

// }

// }
>>>>>>> 7c36852d14850b3d5f0969ba961b492cc37665fc
