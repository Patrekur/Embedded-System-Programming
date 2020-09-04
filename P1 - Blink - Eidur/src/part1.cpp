#include <Arduino.h>

// Variables initialized
unsigned long before = 0;
unsigned long time = 0;
int val = 0;

// Delay function
// Integer sum is used by default for the function
void busyWait(int millis) {
int c = 0;
//int64_t c = 0;
//double c = 0;
//int c = 9;
for (int i = 0; i < millis; i++)
  {
    for (int j = 0; j < 545; j++) {
      c += 9; 
      //c /= 9;    
      //c *= 9;  
    }
  }
}

// Function to get the value from the ADC
int getVal() {

  // ADC conversion started
  ADCSRA = ADCSRA | (1 << ADSC);
  // Wait while conversion is in progress
  while(ADCSRA & (1 << ADSC));
  
  return ADCH;

}

void setup() {

  //Setting built in led as output
  DDRB |= (1 << PB5);
  //Setting A0 as input
  DDRC &= (0 << PC0);
  // Left justified data representation with AVCC as reference
  // and ADC0 as input
  ADMUX = 0b01100000;
  // Prescaler set to maximum 128 - clock rate at 125 kHz
  ADCSRA = 0b10000111;
  Serial.begin(9600);
}

void loop() {
  val = getVal();
  // Toggle LED 
  PORTB ^= (1 << PB5);
  //before = millis();
  busyWait(val*4);
  //time = millis() - before;   
  //Serial.println(time);            

}