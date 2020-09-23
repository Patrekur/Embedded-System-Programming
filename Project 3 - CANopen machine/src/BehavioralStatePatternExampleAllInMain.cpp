#include <Arduino.h>
#include "analog_in.h"
#include "analog_out.h"
#include "digital_out.h"
#include "filter.h"

/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the Context object, associated
 * with the State. This backreference can be used by States to transition the
 * Context to another State.
 */

class Context;

class State {
  /**
   * @var Context
   */

 protected:
  Context *context_;

 public:
  virtual ~State() {
  }

  void set_context(Context *context) {
    this->context_ = context;
  }

  virtual void OnEntry() = 0;
  virtual void OnExit() = 0;
  virtual void Reset() = 0;
  virtual void Housekeeping() = 0;
  virtual void Do() = 0;
};

/**
 * The Context defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the Context.
 */

class Context {
  /**
   * @var State A reference to the current state of the Context.
   */

 private:
  State *state_;

 public:

  Context(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }

  ~Context() {
    delete state_;
  }

  /**
   * The Context allows changing the State object at runtime.
   */

  void TransitionTo(State *state) {
    Serial.println("Context: Transition");

    if (this->state_ != nullptr) {
      this->state_->OnExit();
      delete this->state_;
    }

    this->state_ = state;
    this->state_->set_context(this);
    this->state_->OnEntry();
  }

  /**
   * The Context delegates part of its behavior to the current State object.
   */

  void Reset() {
    this->state_->Reset();
  }

};

/**
 * Concrete States implement various behaviors, associated with a state of the
 * Context.
 */

class Initialization : public State {
 public:
   void OnEntry() override {
     

    
  }

  void OnExit() override {
    Serial.println("Exiting ConcreteStateA.");
  }

  void Reset() override;

};

class Operational : public State {
 public:
  void OnEntry() override {
    Serial.println("Entering ConcreteStateB.");
  }

  void OnExit() override {
    Serial.println("Exiting ConcreteStateB.");
  }

  void Reset() override {
    Serial.println("ConcreteStateB handles Request1.");
  }

  void Housekeeping() override {



  }

  void Do() override {


  }

  
  }

};

void Initialization::Reset() {
  {
    Serial.println("ConcreteStateA handles Request1.");
    Serial.println("ConcreteStateA wants to change the state of the context.");
    this->context_->TransitionTo(new Operational);
  }
}

Context *context;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  context = new Context(new Initialization);
}

void loop() {
  // put your main code here, to run repeatedly:
  context->Housekeeping

  if(Serial.available())
  {
    switch (Serial.readuntil())
    {
      case '1':
        context->Reset();
        break;
    }
  }
}