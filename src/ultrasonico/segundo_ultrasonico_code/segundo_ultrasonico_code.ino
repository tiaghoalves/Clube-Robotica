const int TrigPin = 11;
const int EchoPin = 10;

const int PotPin = A5;

int distancia_ultrasonica = 0;

const int led = 13;

void setup(){

pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);

pinMode(led, OUTPUT);

Serial.begin(9600);

}

void loop() {

ultrasonico();

//map(value, fromLow, fromHigh, toLow, toHigh)
int distancia_de_ativacao = map(analogRead(PotPin), 0, 1023, 0, 450);

if(distancia_ultrasonica <= distancia_de_ativacao){ 
  
  digitalWrite(led ,HIGH);
  
}else{
  
 digitalWrite(led, LOW); 
  
}
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
