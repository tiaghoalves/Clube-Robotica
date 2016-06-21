const int infra1 = 11;
const int infra2 = 10;
const int receptor1 = 6;
const int receptor2 = 7;
const int ledRed = 9;
const int ledGreen = 8;

byte iv;

void setup() {
  pinMode(infravermelho, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  iv = digitalRead(receptorInfravermelho);
  Serial.println(iv);
  delay(200);
  
  if (iv == 1) {
    alcanceUm();
    iv = analogRead(receptorInfravermelho);
    digitalWrite();
  } else {
    alcanceDois();
    iv = analogRead(receptorInfravermelho);
    digitalWrite();
  }
  
}

void alcanceUm(){
  for (byte i = 1; i <= 40; i++) {
    digitalWrite(infravermelho, HIGH);
    delayMicroseconds(13);
    digitalWrite(infravermelho, LOW);
    delayMicroseconds(13);
  }
}

void alcanceDois(){
  for (byte i = 1; i <= 38; i++) {
    digitalWrite(infravermelho, HIGH);
    delayMicroseconds(13);
    digitalWrite(infravermelho, LOW);
    delayMicroseconds(13);
  }
}







