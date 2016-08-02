#include <Servo.h>

Servo servo;

const int PotPin = A5;


void setup() {
  
  servo.attach(11);
  
  Serial.begin(9600);
  
}

void loop() {
  
  
//map(value, fromLow, fromHigh, toLow, toHigh)
int controle = map(analogRead(PotPin), 0, 1023, 0, 180);
  
  servo.write(controle);
  //90 = parado 180 = girar para um lado 0 = girar para o outro lado
  
  Serial.println(controle);


}
