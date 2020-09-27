#ifndef STATES_H
#define STATES_H
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

  // !!Þurfum að breyta Handle í eventa sem þarf að implementa fyrir hvert state!!
// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)
  virtual void OnEntry() = 0;
  virtual void OnExit() = 0;
  virtual void Reset() = 0;
  virtual void Configure() = 0;
  virtual void setPreOp() = 0;
  virtual void setOp() = 0;
  virtual void clearFault() = 0;
   
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

};

#endif