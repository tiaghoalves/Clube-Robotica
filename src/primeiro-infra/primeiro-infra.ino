const int receptor = 7;
byte iv;
int count = 0;

void setup()
{
  pinMode(receptor, INPUT);
  Serial.begin(9600);
}

void loop()
{
  iv = digitalRead(receptor);
  Serial.println(count);
  
  if (iv == 0) {
    count++;
  }
  if(count > 10){
    count = 0;
  }
}

