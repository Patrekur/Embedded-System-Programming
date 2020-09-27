#include "context.h"

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

  void Request1() {
    this->state_->Handle1();
  }

  void Request2() {
    this->state_->Handle2();
  }

};
