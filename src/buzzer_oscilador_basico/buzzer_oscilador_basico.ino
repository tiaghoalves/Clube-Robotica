const int buzzer = 11;

void setup() {

pinMode(buzzer, OUTPUT);
  
}

void loop() {
 //este for vai de 10 hz ate 3000 hz
  for(int i = 10; i <= 3000; i++){
    
  tone(buzzer, i);
    
  }

}
