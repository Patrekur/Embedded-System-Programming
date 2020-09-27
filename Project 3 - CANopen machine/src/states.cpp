#include "states.h"

//---------- Initialize member functions------------------

void Initialize::OnEntry() {
    //ledOut.init();
    Serial.println("Entering Initialize.");
    Serial.print("Initializing...");delay(1000);
    Serial.print("|3");delay(1000);Serial.print("|2");
    delay(1000);Serial.println("|1|");delay(1000);
    this->context_->TransitionTo(new Pre_operational);
  }

  void Initialize::OnExit() {
    Serial.println("Exiting Initialize.");
  }

// !!Þurfum að breyta Handle í eventa sem þarf að implementa fyrir hvert state!!
// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)

  void Initialize::Reset() {
      Serial.println("Initialize handles reset request (1).");
      Serial.println("Initialize wants to change the state of the context.");
      this->context_->TransitionTo(new Initialize);
 }

  void Initialize::Configure() {
    Serial.println("Initialize handles configure request (2).");
  }

  void Initialize::setPreOp() {

    Serial.println("Initialize: Going to preop");

  }

  void Initialize::setOp() {

    Serial.println("Initialize: Do nothing");

  }

  void Initialize::clearFault() {

    Serial.println("Initialize: Do nothing");

  }

// ------------------Pre_operational member functions--------------------------

  void Pre_operational::OnEntry() {
    Serial.println("Entering Pre_operational.");
    Serial.println("press: 1 - for reset(), 2 - for configure(), 3 - for setOp(), 4 for setPreOp().");
    //Serial.println("Pre_operational::OnEntry() -calls- Pre_operational::Configure()");
    //Pre_operational::Configure();
  }

  void Pre_operational::OnExit() {
    Serial.println("Exiting Pre_operational.");
  }

  void Pre_operational::Reset() {
    Serial.println("Pre_operational: Resetting");
    this->context_->TransitionTo(new Initialize);
  }

  void Pre_operational::Configure() {
    Serial.println("Pre_operational: Configure");
    //this->context_->TransitionTo(new ConcreteStateA);
    Serial.println("Here we should be able to set parameters for digital_out");
  }

   void Pre_operational::setPreOp() {
     Serial.println("Pre_operational: setPreOp() - do nothing");
    
    //this->context_->TransitionTo(new Preop);
  }

   void Pre_operational::setOp() {
    Serial.println("Pre_operational: setOp() - Going to Op");
    this->context_->TransitionTo(new Operational);
    
  }

   void Pre_operational::clearFault() {

     Serial.println("Pre_operational: Clearfault - do nothing");
  }

  // ------------------Operational member functions--------------------------

  void Operational::OnEntry() {
    Serial.println("Entering Operational.");
    Serial.println("press: 1 - for reset(), 2 - for configure(), 3 - for setOp(), 4 for setPreOp().");
  }

  void Operational::OnExit() {
    Serial.println("Exiting Operational.");
  }

  void Operational::Reset() {
    Serial.println("Operational: Resetting. Going back to Initialize state");
    this->context_->TransitionTo(new Initialize);
  }

  void Operational::Configure() {
    Serial.println("Operational: Configure() - do nothing");
    //this->context_->TransitionTo(new ConcreteStateA);
  }

   void Operational::setPreOp() {
    Serial.println("Operational: setPreOp(): Going to preop");
    this->context_->TransitionTo(new Pre_operational);
  }
  
   void Operational::setOp() {
    
    Serial.println("Operational: setOp() - do nothing");

  }

   void Operational::clearFault() {

     Serial.println("Operational: Clearfault - do nothing");

  }

  