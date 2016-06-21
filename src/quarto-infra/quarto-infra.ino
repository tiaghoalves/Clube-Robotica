const int infravermelho = 6;

const int receptorInfravermelho = 7;
const int led = 13;
byte iv;

void setup() {
  pinMode(infravermelho, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  for (byte i = 1; i <= 38; i++) {
    digitalWrite(infravermelho, HIGH);
    delayMicroseconds(13);
    digitalWrite(infravermelho, LOW);
    delayMicroseconds(13);
  }
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
  for (byte i = 1; i <= 36; i++) {
    digitalWrite(infravermelho, HIGH);
    delayMicroseconds(13);
    digitalWrite(infravermelho, LOW);
    delayMicroseconds(13);
  }
}







