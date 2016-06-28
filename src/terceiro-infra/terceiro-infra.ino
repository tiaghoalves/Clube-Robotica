const int infravermelho = 10;
const int receptorInfravermelho = 7;
const int led = 13;
byte iv;

void setup() {
  pinMode(infravermelho, OUTPUT);
  pinMode(receptorInfravermelho, INPUT);
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
  
  if (iv == 0) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}
