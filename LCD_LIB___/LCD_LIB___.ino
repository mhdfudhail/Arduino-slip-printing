#include <LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);

void setup() {
  
  lcd.begin(16, 2);
  
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("HELLO WORLD!");
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}
