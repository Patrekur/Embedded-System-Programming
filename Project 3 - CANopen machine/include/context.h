#ifndef CONTEXT_H
#define CONTEXT_H
#include "states.h"

class State;

class Context {

 private:
  State *state_;

 public:

  Context(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }

  ~Context() {
    delete state_;
  }

  void TransitionTo(State *state);
  void Reset();
  void Configure();

};

#endif