#include <Arduino.h>

unsigned long before = 0;
unsigned long after = 0;
unsigned long time = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void busyWait(int millis) {
unsigned long c = 0;
for (int i = 0; i < millis; i++)
  {
    for (unsigned long long j = 0; j < 136; j++) {
      c += 9;        
    }
  }
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("started");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //delay(1000);   // wait for a second
  before = millis();
  busyWait(50000);
  after = millis();
  time = after - before;   
  Serial.println("time = ");
  Serial.println(time);            
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   busyWait(500);
  //delay(1000);                       // wait for a second

}