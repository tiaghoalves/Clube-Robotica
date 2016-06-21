const int LED = 13;
const int potenciometro = A1;
const int LDR = A2;

int valorPotenciometro;
int valorLDR;
int pwm;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  valorLDR =  analogRead(LDR);
  valorPotenciometro = analogRead(potenciometro);

  pwm = map(valorPotenciometro, 0, 2023, 0, 255);

  if (valorLDR >= 800) {
    digitalWrite(LED, pwm);
  } else {
    digitalWrite(LED, LOW);
  }

}
