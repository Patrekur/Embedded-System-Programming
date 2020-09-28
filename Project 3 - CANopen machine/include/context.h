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

  // Input / Output functions used in main
  void init();
  void toggleStatus();
  void hiStatus();
  void loStatus();
  // Timer functions
  void timeStart();
  void timeStop();
  void incrTime();
  bool isFinished();
  void setfreq(int freq);
  // Led out functions
  void outHi();
  void outLo();
  // PWM out functions
  void pwmstart();
  void pwmstop();
  void pwmset(float duty);
  void changemode();
  // Analog infunctions
  int getVal();

  // Status functions
  void TransitionTo(State *state);
  void Reset();
  void Configure();
  void setOp();
  void setPreOp();
  void clearFault();
  void housekeeping();
  void dostuff();

};

#endif