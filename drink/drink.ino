 #include <LiquidCrystal.h>
/*
 WELCOME TO THE AUTO-INEBRIATOR SOURCE CODE!
 Where documentation is sparse, and the whole thing has been lost twice!
 ------------------------
 By Sina Khalili and Sterling Smith
 ------------------------
 */
int buttonUp = 3;
int buttonDown = 4;
int buttonSelect = 5; 
int pumpA = A5;
int pumpB = A4;
int currMenu = 0;
int another = 0;
char* options[]= {"Dark & Stormy", "Margarita", "Jaeger Bomb"};
//int sensorPin = 2;
int sensorValue = 0;
LiquidCrystal lcd(8, 6, 9, 10, 11 , 7);
// the setup routine runs once when you press reset:
void setup() {
  
  lcd.begin(16, 2);
  lcd.setCursor(0,1);
  lcd.write("Select drink!   "); 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(buttonUp, INPUT);
  pinMode(buttonDown, INPUT);
  pinMode(pumpA, OUTPUT);
  pinMode(pumpB, OUTPUT);
  digitalWrite(pumpA, HIGH);
  digitalWrite(pumpB, HIGH);
}

void pumpFunc(int pump, int dval){
  digitalWrite(pump, LOW);
  delay(dval);
  digitalWrite(pump, HIGH);
}

int makeDrink(int a, int b){
  pumpFunc(pumpA, a);
  pumpFunc(pumpB, b);
}

// the loop routine runs over and over again forever:
void loop() {
  
  lcd.setCursor(0,1);
  lcd.write("Select drink!   ");
  int buttonFlag = 0;
  Serial.println("Waiting for button push...");
  while(true){
    if(digitalRead(buttonUp) != LOW){
      currMenu++;
      currMenu = currMenu%3;
      Serial.println(currMenu);
      Serial.println("UP pressed");
      lcd.setCursor(0,0);
      lcd.write("                "); 
      lcd.setCursor(0,0);
      lcd.write(options[currMenu]); 
      delay(300);
      }   
    if(digitalRead(buttonDown) != LOW){
      Serial.println("Down pressed");
      
      currMenu--;
      currMenu<0? currMenu = 2: currMenu = currMenu;
      Serial.println(currMenu);
      lcd.setCursor(0,0);
      lcd.write("                "); 
      lcd.setCursor(0,0);
      lcd.write(options[currMenu]); 
      delay(300);
      }
     if(digitalRead(buttonSelect) != LOW){
      Serial.println("Select pressed");
      lcd.setCursor(0,0);
      lcd.write("Making drink:   "); 
      lcd.setCursor(0,1);
      lcd.write("                "); 
      lcd.setCursor(0,1);
      lcd.write(options[currMenu]); 
      break;
     }
  }
  
 switch (currMenu) {
    case 0:
      makeDrink(5000,1000);
    break;
    case 1:
      makeDrink(1000,1000);
    break;
    case 2:
      makeDrink(2000,2000);
    break;
  }
  //while(state 
  Serial.println("Button has been pushed");
  //Serial.println(buttonFlag);
  lcd.setCursor(0,0);
  lcd.write("Make another?   ");
  lcd.setCursor(0,1);
  lcd.write(">Yes  No        ");
  another = 1;
  while(true){
     
    if(digitalRead(buttonUp) != LOW){
     another = 1;
     Serial.println(currMenu);
     Serial.println("UP pressed");
     lcd.setCursor(0,1);
     lcd.write(">Yes  No        ");
     delay(300);
      }   
    if(digitalRead(buttonDown) != LOW){
      another = 0;
      Serial.println("Down pressed");
      Serial.println(currMenu);
      lcd.setCursor(0,1);
      lcd.write(" Yes >No");
      delay(300);
      } 
     if(digitalRead(buttonSelect) != LOW && another == 1){

      Serial.println("Down pressed");
      Serial.println(currMenu);
      lcd.setCursor(0,1);
      lcd.write("Restarting!");
      delay(500);
      break;
      }  
  }   
}



