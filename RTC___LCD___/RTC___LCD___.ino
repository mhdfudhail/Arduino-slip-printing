#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"

LiquidCrystal lcd(4,5,6,7,8,9);
RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  while (!Serial);

  Serial.begin(57600);
  lcd.begin(16, 2);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");

}
}

void loop() {
  

  DateTime now = rtc.now();

    lcd.setCursor(0,0);
    lcd.print("DATE- ");
    Serial.print(now.year(), DEC);
    lcd.print(now.year(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.month(), DEC);
    lcd.print(now.month(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.day(), DEC);
    lcd.print(now.day(), DEC);
    Serial.print(" (");
    
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    lcd.setCursor(0,1);
    lcd.print("TIME- ");
    Serial.print(now.hour(), DEC);
    lcd.print(now.hour(), DEC);
    Serial.print(':');
    lcd.print(':');
    Serial.print(now.minute(), DEC);
    lcd.print(now.minute(), DEC);
    Serial.print(':');
    lcd.print(':');
    Serial.print(now.second(), DEC);
    lcd.print(now.second(), DEC);
    Serial.println();
    
 
    delay(1000);

}
