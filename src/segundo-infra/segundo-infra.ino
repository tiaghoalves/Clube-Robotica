const int receptor = 7;
const int ledRed = 13;
const int ledGreen = 12;
const int ledYellow = 11;

byte iv;
int count = 0;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(receptor, INPUT);
  Serial.begin(9600);
}

void loop() {
  iv = digitalRead(receptor);
  Serial.println(count);

  if (iv == 0) {
    count++;
  }
  
  //usandoIfElse();

  usandoSwitchCase();
}

void usandoSwitchCase(){
  switch(count){
      case 10: digitalWrite(ledRed, HIGH);
        break;
      case 20: digitalWrite(ledGreen, HIGH);
        break;
      case 30: digitalWrite(ledYellow, HIGH);
        break;
      case 40: digitalWrite(ledRed, LOW);
               digitalWrite(ledGreen, LOW);
               digitalWrite(ledYellow, LOW);
        break;
   }
}

void usandoIfElse(){
  if (count >= 5 && count < 10) {
    digitalWrite(ledRed, HIGH);
  } else {
    if (count >= 10 && count < 15) {
      digitalWrite(ledGreen, HIGH);
    } else {
      if (count >= 15) {
        digitalWrite(ledYellow, HIGH);
      }
    }
  }
  
  if(count > 30){
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
  }
}


