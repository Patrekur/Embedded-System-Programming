#include "states.h"

// Initialize member functions

void Initialize::OnEntry() {
    //ledOut.init();
  }

  void Initialize::OnExit() {
    Serial.println("Exiting ConcreteStateA.");
  }

// !!Þurfum að breyta Handle í eventa sem þarf að implementa fyrir hvert state!!
// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)

void Initialize::Reset() {
  {
    Serial.println("ConcreteStateA handles Request1.");
    Serial.println("ConcreteStateA wants to change the state of the context.");
    //this->context_->TransitionTo(new Operational);
  }
}

  void Initialize::Configure() {
    Serial.println("ConcreteStateA handles Request2.");
  }

  void Initialize::setPreOp() {

    Serial.println("Init: Going to preop");

  }

  void Initialize::setOp() {

    Serial.println("Init: Do nothing");

  }

  void Initialize::clearFault() {

    Serial.println("Init: Do nothing");

  }



  // Operational member functions

  void Operational::OnEntry() {
    Serial.println("Entering ConcreteStateB.");
  }

  void Operational::OnExit() {
    Serial.println("Exiting ConcreteStateB.");
  }

  void Operational::Reset() {
    Serial.println("Op: Resetting");
  }

  void Operational::Configure() {
    Serial.println("Op: Configure");
    //this->context_->TransitionTo(new ConcreteStateA);
  }

   void Operational::setPreOp() {
    Serial.println("Op: Going to preop");
    //this->context_->TransitionTo(new Preop);
  }

   void Operational::setOp() {
    
    Serial.println("Op: go to op - do nothing");

  }

   void Operational::clearFault() {

     Serial.println("Op: Clearfault - do nothing");

  }