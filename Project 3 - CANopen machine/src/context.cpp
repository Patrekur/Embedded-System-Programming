#include "context.h"

  void Context::TransitionTo(State *state) {
    Serial.println("Context: Transition");

    if (this->state_ != nullptr) {
      this->state_->OnExit();
      delete this->state_;
    }

    this->state_ = state;
    this->state_->set_context(this);
    this->state_->OnEntry();
  }
  
  void Context::toggleStatus() {

    ledStatus.toggle();

  }

  void Context::Reset() {
    Serial.println("Context: Resetting");
    this->state_->Reset();
  }

  void Context::Configure() {
    Serial.println("Context: configuring");
    this->state_->Configure();
  }
  void Context::setOp() {
    Serial.println("Context: configuring"); 
    this->state_->setOp();
  }
   void Context::setPreOp() {
    Serial.println("Context: configuring"); 
    this->state_->setPreOp();
  }

