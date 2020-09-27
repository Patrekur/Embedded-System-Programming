
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
  void Request1();
  void Request2();

};

