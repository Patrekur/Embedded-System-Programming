#ifndef STATES_H
#define STATES_H
//#include <Arduino.h>
#include "context.h"

class Context;

class State {

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
  virtual void Configure() = 0;
  virtual void setPreOp() = 0;
  virtual void setOp() = 0;
  virtual void clearFault() = 0;
  virtual void dostuff() = 0;
   
  };

class Initialize : public State {
 public:
  
  void OnEntry();
  void OnExit();
  void Reset();
  void Configure();
  void setPreOp();
  void setOp();
  void clearFault();
  void dostuff();

};

class Operational : public State {
 
 public:
  void OnEntry();
  void OnExit();
  void Reset();
  void Configure();
  void setPreOp();
  void setOp();
  void clearFault();
  void dostuff();

};

class Pre_operational : public State {
  void OnEntry();
  void OnExit();
  void Reset();
  void Configure();
  void setPreOp();
  void setOp();
  void clearFault();
  void dostuff();
};

class Stopped : public State {
  void OnEntry();
  void OnExit();
  void Reset();
  void Configure();
  void setPreOp();
  void setOp();
  void clearFault();
  void dostuff();
};

#endif