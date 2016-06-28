const int infra1 = 11;
const int infra2 = 10;
const int receptor1 = 6;
const int receptor2 = 7;
const int ledRed = 9;
const int ledGreen = 8;

int count = 0;

byte iv1;
byte iv2;

void setup() {
  pinMode(infra1, OUTPUT);
  pinMode(infra2, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  for (byte i = 1; i <= 38; i++) {
    digitalWrite(infra1, HIGH);
    delayMicroseconds(13);
    digitalWrite(infra1, LOW);
    delayMicroseconds(13);
  }
  // primeira leitura
  iv1 = digitalRead(receptor1);
  Serial.println(iv1);
  delay(200);

  for (byte i = 1; i <= 38; i++) {
    digitalWrite(infra2, HIGH);
    delayMicroseconds(13);
    digitalWrite(infra2, LOW);
    delayMicroseconds(13);
  }
  // segunda leitura
  iv2 = digitalRead(receptor2);
  Serial.println(iv2);
  delay(200);

  // incrementa o contador quando uma das leituras for 'cortada'
  if(iv1 == 0 || iv2 == 0){
    count++;
  }

   switch(count){
      case 10: 
              digitalWrite(ledRed, HIGH);
        break;
      case 20: digitalWrite(ledGreen, HIGH);
        break;
      case 50: digitalWrite(ledRed, LOW);
               digitalWrite(ledGreen, LOW);
               count = 0;
        break;
   }
  
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








