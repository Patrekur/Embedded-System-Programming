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

  void Context::init() {

    // Initalizing helper classes
    ledStatus.setpin(5);
    ledOut.setpin(3);
    input.init();
    output.init();
    output.stop();
    ledStatus.init();
    ledOut.init();
    ledOut.toggle();
    tim.init();

  }

  // Status led functions

  void Context::toggleStatus() {

    ledStatus.toggle();

  }

void Context::hiStatus() {

  ledStatus.set_hi();

}

void Context::loStatus() {

  ledStatus.set_lo();

}

  // Time functions

  bool Context::isFinished() {

    return tim.isFinished();

  }

  void Context::incrTime() {

    tim.incrTime();

  }

  void Context::timeStart() {

    tim.start();

  }

  void Context::timeStop() {

    tim.stop();

  }

  void Context::setfreq(int freq) {

    tim.changeTimeout(freq);

  }

  // Output led functions

  void Context::outHi() {

    ledOut.set_hi();

  }
  void Context::outLo() {

    ledOut.set_lo();

  }

  // Analog out functions

  void Context::pwmstart() {

    output.start();

  }

  void Context::pwmstop() {

    output.stop();

  }

  void Context::pwmset(float duty) {

    output.dutyset(duty);

  }

  void Context::changemode() {

    output.changemode();

  }

  // Analog in functions

  int Context::getVal() {

     return input.getval();

  }

  // State functions
  
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

  void Context::clearFault() {

    this->state_->clearFault();

  }

  void Context::housekeeping() {

    if(Serial.available())
    {
      switch (Serial.read())
      {
        // State 
        case '1':
          this->Reset();
          break;
        case '2':
          this->Configure();
          break;
        case '3':
          this->setOp();
          break;
        case '4':
          this->setPreOp();
          break;
        case '5':
          this->clearFault();
      }
    }

  }

  void Context::dostuff() {

    this->state_->dostuff();

  }

