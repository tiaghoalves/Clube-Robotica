const int botao = 7;
const int led = 13;

int leitura_botao = 0;

void setup() {
  
Serial.begin(9600);

pinMode(botao, INPUT);
pinMode(led, OUTPUT);

}

void loop() {

  leitura_botao = digitalRead(botao);
  Serial.println(leitura_botao);
  
  if(leitura_botao == 1){ 
    
    digitalWrite(led, HIGH);
    //se o botao for pressionado liga o led
     
  }else{
    
    digitalWrite(led, LOW);
    //se o botao nao estiver sendo pressionado desliga o led
    
  }
  
  

}
