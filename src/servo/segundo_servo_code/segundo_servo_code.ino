#include <Servo.h>

Servo servo;

const int TrigPin = 10;
const int EchoPin = 9;

int distancia_ultrasonica = 0;

void setup() {

  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  
  servo.attach(11);
  
  Serial.begin(9600);

}

void loop() {
  
  ultrasonico();
 
//map(value, fromLow, fromHigh, toLow, toHigh)
int controle = map(distancia_ultrasonica, 0, 450, 0, 180);

  servo.write(controle);
  //90 = parado 180 = girar para um lado 0 = girar para o outro lado
  
  Serial.println(controle);

}



void ultrasonico(){

  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(13);
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  
  int leitura_echo = pulseIn(EchoPin, HIGH);

  distancia_ultrasonica = leitura_echo / 58;

  Serial.print(distancia_ultrasonica);
  Serial.println("cm");
  Serial.println();

}
