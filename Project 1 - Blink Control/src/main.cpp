#include <Arduino.h>
// the setup function runs once when you press reset or power the board



int time;
int before;
unsigned int startTimer;
int compareTimer;
int c;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

int busyWait(unsigned int t){
  startTimer = millis();
//  while(millis() - startTimer < t) {
//    // wait for t ms
//  }
c = 10; 
  for(int i = 0; i < c; i++){
    for(int j = 0; j < c; j++){
      c = c + 1;
      if(millis() - startTimer > t){
        c = 0;
      }
    }
  }
}




// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);   // wait for a second
  before = millis();
  busyWait(1000);
  //delay(1000);
  time =  millis() - before;               
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   busyWait(1000); 
  //delay(1000);                       // wait for a second
  Serial.println("time = ");
  Serial.println(time );
}

