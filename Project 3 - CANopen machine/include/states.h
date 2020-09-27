#ifndef STATES_H
#define STATES_H
#include <arduino.h>
#include "context.h"

class Initialize : public State {
 public:
   void OnEntry() override {
    Serial.println("Entering ConcreteStateA.");
  }

  void OnExit() override {
    Serial.println("Exiting ConcreteStateA.");
  }

  void Handle1() override;

  void Handle2() override {
    Serial.println("ConcreteStateA handles Request2.");
  }

};

class Operational : public State {
 public:
  void OnEntry() override {
    Serial.println("Entering ConcreteStateB.");
  }

  void OnExit() override {
    Serial.println("Exiting ConcreteStateB.");
  }

  void Handle1() override {
    Serial.println("ConcreteStateB handles Request1.");
  }

  void Handle2() override {
    Serial.println("ConcreteStateB handles Request2.");
    Serial.println("ConcreteStateB wants to change the state of the context.");
    this->context_->TransitionTo(new ConcreteStateA);
  }

};

void Initialize::Handle1() {
  {
    Serial.println("ConcreteStateA handles Request1.");
    Serial.println("ConcreteStateA wants to change the state of the context.");
    this->context_->TransitionTo(new ConcreteStateB);
  }
}

#endif