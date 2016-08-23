// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 8, 5, 4, 3, 2);

//define pins for potentiometer and button
#define potPin A0
#define butPin 7

// led variables
int redpin = 9;    //Pin 9
int greenpin = 10;  //Pin 10
int bluepin = 11;    //Pin 11
int var = 0;
int var1 = 0;

// buzzer
#define buzPin 13
#define buzPin1 0

// create variables to store potentiometer's and button's value
int butVal;
int potVal = 0;
byte bufferPot[] = {0, 0, 0, 0};
// will be used to compensate deslocations made on the display
int cursorDesloc;
// save initials
char firstInitial;
char lastInitial;
// alphabet char array
char alfabeto[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char letter;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  pinMode(butPin, INPUT);
  pinMode(buzPin, OUTPUT);
  pinMode(buzPin1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(buzPin1, LOW);

  led();

  digitalWrite(buzPin, HIGH);
  delay(500);
  digitalWrite(buzPin, LOW);
  digitalWrite(buzPin1, HIGH);

  // get potentiometer's and button's state/value
  butVal = digitalRead(butPin);
  // print on row 0
  lcd.print("Aperte o botao");
  // move cursor to row 1
  lcd.setCursor(0, 1);
  // print on row 1
  lcd.print("para comecar!");
  if (butVal) {
    askingInitials();
  }
  delay(2000);
  lcd.clear();
}

void askingInitials() {
  // clear previous text
  lcd.clear();
  // print on row 0
  lcd.print("Diga-me suas");
  // move the cursor to the start of the row 1
  lcd.setCursor(0, 1);
  // print on row 1
  lcd.print("iniciais :)");
  delay(5000);
  // clear the screen
  lcd.clear();
  // move the cursor to the star of the row 0
  lcd.setCursor(0, 0);
  // print on row 0
  lcd.print("Qual e a inicial");
  delay(2000);
  // move the cursor to the start of the row 1
  lcd.setCursor(0, 1);
  // print on row 1
  lcd.print("do seu primeiro nome?");
  delay(2000);
  // clear all
  lcd.clear();
  //  // scroll to show the rest of the question (" nome?")
  //  for(cursorDesloc = 0; cursorDesloc < 6; cursorDesloc++) {
  //    // scroll one position right:
  //    lcd.scrollDisplayLeft();
  //    // wait a bit:
  //    if(cursorDesloc < 5) {
  //      delay(50);
  //    }
  //  }
  //  // print on row 1 again
  //  lcd.setCursor(0, 1);
  //  lcd.print(" primeiro nome?");
  //  // move cursor to row 0
  //  lcd.setCursor(0, 0);
  //  // print the content of row 0 again so it will be pretty
  //  lcd.print("Qual e a inicial");
  //  delay(1000);
  //  // clear all
  //  lcd.clear();
  // print a letter based on potentiometer's value on row 1
  delay(50);
//  do {
    // read the potentiometer's value
//    potVal = analogRead(potPin);
//    Serial.println(potVal);
//    Serial.println(butVal);
//    for (int i = 1; i < 27; i++) {
//      if (potVal < 40 * i) {
//        letter = alfabeto[i - 1];
//        break;
//      }
//    }
    letter = Serial.read();
    // cursor to row 0
    lcd.setCursor(0, 0);
    // print on row 0
    lcd.print(" primeiro nome?");
    // cursor to row 1
    lcd.setCursor(0, 1);
    // print letter
    lcd.print(letter);
    delay(200);
    lcd.clear();
    // verify button value
    butVal = digitalRead(butPin);
    if (butVal) {
      int firstInitial = letter;
    }
  } while (!butVal);
  // just for matter of testing
  lcd.clear();
  delay(20);
  lcd.print(firstInitial);

  // clear after 5s
  delay(5000);
  lcd.clear();
}

void led() {
  for (var1 = 255; var1 < 256; var1++)
  {
    analogWrite(redpin, var1);  //YELLOW
    analogWrite(greenpin, var1);
    delay(500 * 2);
    analogWrite(redpin, 0);
    delay(500 * 2);
    analogWrite(greenpin, var1); //CYAN
    analogWrite(bluepin, var1);
    delay(500 * 2);
    analogWrite(greenpin, 0);
    delay(500 * 2);
    analogWrite(bluepin, var1);   //MAGENTA
    analogWrite(redpin, var1);
    delay(500 * 2);
    analogWrite(bluepin, 0);
    delay(500 * 2);
    analogWrite(bluepin, var1);
    analogWrite(redpin, var1);
    analogWrite(greenpin, var1);
    delay(1000 * 2);
  }
}

