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

void Context::Request1() {
    this->state_->Handle1();
  }

  void Context::Request2() {
    this->state_->Handle2();
  }


