// #include <Arduino.h>
// #include "analog_in.h"
// #include "analog_out.h"
// #include "digital_out.h"
// #include "filter.h"
// #include "timer.h"

// /**
//  * The base State class declares methods that all Concrete State should
//  * implement and also provides a backreference to the Context object, associated
//  * with the State. This backreference can be used by States to transition the
//  * Context to another State.
//  */

// class Context;

// class State {
//   /**
//    * @var Context
//    */

//  protected:
//   Context *context_;

//  public:
//   virtual ~State() {
//   }

//   void set_context(Context *context) {
//     this->context_ = context;
//   }

//   virtual void OnEntry() = 0;
//   virtual void OnExit() = 0;
//   virtual void Handle1() = 0;
//   virtual void Handle2() = 0;
// };

// /**
//  * The Context defines the interface of interest to clients. It also maintains a
//  * reference to an instance of a State subclass, which represents the current
//  * state of the Context.
//  */

// class Context {
//   /**
//    * @var State A reference to the current state of the Context.
//    */

//  private:
//   State *state_;

//  public:

//   Context(State *state) : state_(nullptr) {
//     this->TransitionTo(state);
//   }

//   ~Context() {
//     delete state_;
//   }

//   /**
//    * The Context allows changing the State object at runtime.
//    */

//   void TransitionTo(State *state) {
//     Serial.println("Context: Transition");

//     if (this->state_ != nullptr) {
//       this->state_->OnExit();
//       delete this->state_;
//     }

//     this->state_ = state;
//     this->state_->set_context(this);
//     this->state_->OnEntry();
//   }

//   /**
//    * The Context delegates part of its behavior to the current State object.
//    */

//   void Request1() {
//     this->state_->Handle1();
//   }

//   void Request2() {
//     this->state_->Handle2();
//   }

// };

// /**
//  * Concrete States implement various behaviors, associated with a state of the
//  * Context.
//  */

// class Initialization : public State {
//  public:
//    void OnEntry() override {
//     Serial.println("Entering Initialization state.");
//   }

//   void OnExit() override {
//     Serial.println("Exiting Initialization.");Serial.println();
//   }

//   void Handle1() override;

//   void Handle2() override {
//     Serial.println("Initialization handles Request2.");
//   }

// };

// class Pre_operational : public State {
//  public:
//   void OnEntry() override {
//     Serial.println("Entering Pre_operational state.");
//   }

//   void OnExit() override {
//     Serial.println("Exiting Pre_operational.");Serial.println();
//   }

//   void Handle1() override {
//     Serial.println("Pre_operational handles Request1.");
//   }

//   void Handle2() override {
//     Serial.println("Pre_operational handles Request2.");
//     Serial.println("Pre_operational wants to change the state of the context.");
//     this->context_->TransitionTo(new Initialization);
//   }

// };

// void Initialization::Handle1() {
//   {
//     Serial.println("Initialization handles Request1.");
//     Serial.println("Initialization wants to change the state of the context.");
//     this->context_->TransitionTo(new Pre_operational);
//   }
// }

// /*
// ---------------------------------------------------------------------------------------
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// ---------------------------------------------------------------------------------------
// - - - - - - - - - - - - - - - - - - loop starts here - - - - - - - - - - - - - - - - -  
// ---------------------------------------------------------------------------------------
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ---------------------------------------------------------------------------------------
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// */



// Digital_out ledOut(4); // PB4 : pin 12
// Digital_out ledStatus(5); 
// Analog_in analogIn(0); // Set pinmask to pin 0 eg. A0 on the UNO
// Analog_out output(0.5); // Set the dutycycle to 0.5
// Timer tim(1); // set the timer interval to 1Hz or 2Hz


// float val = 0;
// double IIRVal = 0;


// Context *context;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   context = new Context(new Initialization);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   delay(100);

//   if(Serial.available())
//   {
//     switch (Serial.read())
//     {
//       case '1':
//         context->Request1();
//         break;
//       case '2':
//         context->Request2();
//         break;
//     }
//   }
// }

//   // Timer 1 used for PWM, used by analog out class
//   ISR(TIMER1_COMPB_vect)
//   {

//     ledOut.set_lo();

//   }

//   ISR(TIMER1_COMPA_vect)
//   {

//     ledOut.set_hi();

//   }

//   // Status light interrupt
//   ISR(TIMER2_COMPA_vect) {

//   Serial.println("Interrupt!!");
//   tim.incrTime();

//   if (tim.isFinished()) {

//     ledStatus.toggle();

//   }

// }
