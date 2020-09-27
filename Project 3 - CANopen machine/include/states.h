#ifndef STATES_H
#define STATES_H
#include <arduino.h>
#include "context.h"

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
  virtual void Handle1() = 0;
  virtual void Handle2() = 0;
   
  };

class Initialize : public State {
 public:
  
  void OnEntry() override;
  void OnExit() override;
  void Handle1() override;
  void Handle2() override;

};

class Operational : public State {
 public:
  void OnEntry() override;

  void OnExit() override;

  void Handle1() override;

  void Handle2() override;

};

#endif