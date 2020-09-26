#include <arduino.h>

class Context;

class State {
  /**
   * @var Context
   */

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
