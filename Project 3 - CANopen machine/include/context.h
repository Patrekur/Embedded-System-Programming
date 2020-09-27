#ifndef CONTEXT_H
#define CONTEXT_H
#include "filter.h"
#include "timer.h"
#include "analog_in.h"
#include "analog_out.h"
#include "digital_out.h"
#include "states.h"

class State;

class Context {

 private:
  State *state_;
  Digital_out ledOut;
  Digital_out ledStatus;
  Analog_in input;
  Analog_out output;
  Timer tim;

 public:

  Context(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }

  ~Context() {
    delete state_;
  }

  void init() {

    ledStatus.setpin(5);
    ledOut.setpin(4);
    input.init();
    output.init();
    ledStatus.init();

  };

  void toggleStatus();
  void TransitionTo(State *state);
  void Reset();
  void Configure();

};

#endif