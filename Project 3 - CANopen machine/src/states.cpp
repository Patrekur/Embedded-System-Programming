#include "states.h"

// Initialize member functions

void Initialize::OnEntry() override {
    Serial.println("Entering ConcreteStateA.");
  }

  void Initialize::OnExit() override {
    Serial.println("Exiting ConcreteStateA.");
  }

// !!Þurfum að breyta Handle í eventa sem þarf að implementa fyrir hvert state!!
// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)

void Initialize::Handle1() {
  {
    Serial.println("ConcreteStateA handles Request1.");
    Serial.println("ConcreteStateA wants to change the state of the context.");
    this->context_->TransitionTo(new ConcreteStateB);
  }
}

  void Initialize::Handle2() override {
    Serial.println("ConcreteStateA handles Request2.");
  }

  // Operational member functions

  void Operational::OnEntry() override {
    Serial.println("Entering ConcreteStateB.");
  }

  void Operational::OnExit() override {
    Serial.println("Exiting ConcreteStateB.");
  }

  // !!Þurfum að breyta Handle í eventa sem þarf að implementa fyrir hvert state!!
  // Events:
  // Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)

  void Operational::Handle1() override {
    Serial.println("ConcreteStateB handles Request1.");
  }

  void Operational::Handle2() override {
    Serial.println("ConcreteStateB handles Request2.");
    Serial.println("ConcreteStateB wants to change the state of the context.");
    this->context_->TransitionTo(new ConcreteStateA);
  }