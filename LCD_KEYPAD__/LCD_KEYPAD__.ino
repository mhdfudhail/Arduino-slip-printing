#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(2,3,4,5,6,7);

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'-','0','=','D'}
};
byte rowPins[ROWS] = {8, 9, 10, 11}; 
byte colPins[COLS] = {12, A0, A1, A2}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey != NO_KEY)
  {
   if(customKey == 'A')
   {
    lcd.clear();
   }
    else if(customKey == 'B')
   {
    lcd.setCursor(0,1);
   }
   else
   {
    lcd.print(customKey);
  }
  }
}
