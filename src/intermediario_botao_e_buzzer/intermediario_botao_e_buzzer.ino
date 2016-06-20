
const int buzzer = 11;
const int botao = 7;
const int potenciometro = A5;
//portas analógicas não precisam ser declaradas pois apenas podem ser input

int leitura_botao = 0;
int leitura_potenciometro = 0;
boolean estado = false;

void setup() {
  // put your setup code here, to run once:
pinMode(buzzer, OUTPUT);
pinMode(botao, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  leitura_botao = digitalRead(botao);
  leitura_potenciometro = analogRead(potenciometro);
  
  Serial.println(leitura_botao);
  Serial.println(leitura_potenciometro);
                                                                                                                                       
  if(leitura_botao == 1){
   
    do{     
        leitura_botao = digitalRead(botao);
      
    }while(leitura_botao == 1);
    
    estado = !estado;
  }
  
  if(estado==true){
    
   tone(buzzer, leitura_potenciometro); 
    
  }else{
    
   noTone(buzzer); 
    
  }


}
