/**
 * The base State class declares methods that all Concrete State should
 * implement and also provides a backreference to the Context object, associated
 * with the State. This backreference can be used by States to transition the
 * Context to another State.
 */

#include <context.h>
/**
 * The Context defines the interface of interest to clients. It also maintains a
 * reference to an instance of a State subclass, which represents the current
 * state of the Context.
 */

class Context {
  /**
   * @var State A reference to the current state of the Context.
   */

 private:
  State *state_;

 public:

  Context(State *state) : state_(nullptr) {
    this->TransitionTo(state);
  }

  ~Context() {
    delete state_;
  }

  /**
   * The Context allows changing the State object at runtime.
   */

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
class ConcreteStateA : public State {
 public:
   void OnEntry() override {
    Serial.println("Entering ConcreteStateA.");
  }

  void OnExit() override {
    Serial.println("Exiting ConcreteStateA.");
  }

  void Handle1() override;

  void Handle2() override {
    Serial.println("ConcreteStateA handles Request2.");
  }

};

class ConcreteStateB : public State {
 public:
  void OnEntry() override {
    Serial.println("Entering ConcreteStateB.");
  }

  void OnExit() override {
    Serial.println("Exiting ConcreteStateB.");
  }

  void Handle1() override {
    Serial.println("ConcreteStateB handles Request1.");
  }

  void Handle2() override {
    Serial.println("ConcreteStateB handles Request2.");
    Serial.println("ConcreteStateB wants to change the state of the context.");
    this->context_->TransitionTo(new ConcreteStateA);
  }

};

void ConcreteStateA::Handle1() {
  {
    Serial.println("ConcreteStateA handles Request1.");
    Serial.println("ConcreteStateA wants to change the state of the context.");
    this->context_->TransitionTo(new ConcreteStateB);
  }
}