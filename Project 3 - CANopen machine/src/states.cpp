#include "states.h"


//---------- Initialize member functions------------------


void Initialize::OnEntry() {
    this->context_->init();
    this->context_->TransitionTo(new Pre_operational);
  }

  void Initialize::OnExit() {
    
  }

// !!Þurfum að breyta Handle í eventa sem þarf að implementa fyrir hvert state!!
// Events:
// Reset (all states), Configure (Preop), (set)preOp (Stopped, Op), (set)Op (Stopped, Preop), clearFault (Stopped)

void Initialize::Reset() {
  {
    Serial.println("Initialize: reset");
  
  }
}

  void Initialize::Configure() {
    Serial.println("Initialize handles configure request (2).");
  }

  void Initialize::setPreOp() {

    //Serial.println("Initialize: Going to preop");

  }

  void Initialize::setOp() {

    Serial.println("Initialize: Do nothing");

  }

  void Initialize::clearFault() {

    Serial.println("Initialize: Do nothing");

  }

  void Initialize::dostuff() {


  }

// ------------------Pre_operational member functions--------------------------

  void Pre_operational::OnEntry() {
    Serial.println("Entering Pre_operational.");  
    // Frequency of status light at 1 Hz
    this->context_->setfreq(1);
    // Start status timer
    this->context_->timeStart();
    Serial.println("press: 1 - for reset(), 2 - for configure(), 3 - for setOp(), 4 for setPreOp().");
    //Serial.println("Pre_operational::OnEntry() -calls- Pre_operational::Configure()");
    //Pre_operational::Configure();
  }

  void Pre_operational::OnExit() {
    this->context_->timeStop();
    Serial.println("Exiting Pre_operational.");
  }

  void Pre_operational::Reset() {
    Serial.println("Pre_operational: Resetting");
    this->context_->TransitionTo(new Initialize);
  }

  void Pre_operational::Configure() {
    Serial.println("Pre_operational: Configure");
    // Changing the frequency of the output
    this->context_->changemode();
  }

   void Pre_operational::setPreOp() {
     Serial.println("Pre_operational: setPreOp() - do nothing");
    
  }

   void Pre_operational::setOp() {
    Serial.println("Pre_operational: setOp() - Going to Op");
    this->context_->TransitionTo(new Operational);
    
  }

   void Pre_operational::clearFault() {

     Serial.println("Pre_operational: Clearfault - do nothing");
  }

  void Pre_operational::dostuff() {

    int val;
    val = this->context_->getVal();
    if (val == 0 || val == 255) {

      this->context_->TransitionTo(new Stopped);  

    }

  }

  // ------------------Operational member functions--------------------------

  void Operational::OnEntry() {
    Serial.println("Entering Operational.");
    // Start analog out
    this->context_->pwmstart();
    // Status led constant high
    this->context_->hiStatus();
    Serial.println("press: 1 - for reset(), 2 - for configure(), 3 - for setOp(), 4 for setPreOp().");
  }

  void Operational::OnExit() {

    Serial.println("Exiting Operational.");
    this->context_->pwmstop();
    //this->context_->loStatus();
  }

  void Operational::Reset() {
    Serial.println("Op: Resetting");
    this->context_->TransitionTo(new Initialize);
  }

  void Operational::Configure() {
    Serial.println("Operational: Configure() - do nothing");
    //this->context_->TransitionTo(new ConcreteStateA);
  }

   void Operational::setPreOp() {
    Serial.println("Operational: setPreOp(): Going to preop");
    this->context_->TransitionTo(new Pre_operational);
  }
  
   void Operational::setOp() {
    
    Serial.println("Operational: setOp() - do nothing");

  }

   void Operational::clearFault() {

     Serial.println("Operational: Clearfault - do nothing");

  }

  void Operational::dostuff() {
    int val;
    val = this->context_->getVal();
    if (val == 0 || val == 255) {

      this->context_->TransitionTo(new Stopped);  

    }

    this->context_->pwmset((2*val)/float(255));

  }

// ------------------Stopped member functions--------------------------

  void Stopped::OnEntry() {
    Serial.println("Entering Stopped.");
    this->context_->pwmstop();
    this->context_->setfreq(2);
    this->context_->timeStart();
    Serial.println("press: 1 - for reset(), 2 - for configure(), 3 - for setOp(), 4 for setPreOp().");
  }

  void Stopped::OnExit() {

    Serial.println("Exiting Stopped");
    this->context_->timeStop();
  }

  void Stopped::Reset() {
    Serial.println("Stopped: Resetting");
    this->context_->TransitionTo(new Initialize);
  }

  void Stopped::Configure() {
    Serial.println("Stopped: Configure() - do nothing");
    //this->context_->TransitionTo(new ConcreteStateA);
  }

   void Stopped::setPreOp() {
    Serial.println("Stopped: setPreOp(): Going to preop");
    this->context_->TransitionTo(new Pre_operational);
  }
  
   void Stopped::setOp() {
    
    Serial.println("Stopped: Set operational");
    this->context_->TransitionTo(new Operational);

  }

   void Stopped::clearFault() {

     // Checking if error is solved
     if (!(this->context_->getVal() == 0 || this->context_->getVal() == 255)) {

       // If the fault is fixed. Reinitialize
       this->context_->TransitionTo(new Initialize);

     }

  }

  void Stopped::dostuff() {


  }

  

  