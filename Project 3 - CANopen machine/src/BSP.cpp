#include <Arduino.h>


Context *context;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  context = new Context(new ConcreteStateA);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);

  if(Serial.available())
  {
    switch (Serial.read())
    {
      case '1':
        context->Request1();
        break;
      case '2':
        context->Request2();
        break;
    }
  }
}