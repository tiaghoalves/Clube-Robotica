#include <Servo.h>
Servo servo;
const int TrigPin = 10;
const int EchoPin = 9;

void setup() {  
pinMode(TrigPin, OUTPUT);  
pinMode(EchoPin, INPUT);    
servo.attach(11);    
Serial.begin(9600);}

void loop() {
servo.write(90);  
}

