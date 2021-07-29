#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include<LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(2,3,4,7,8,9);

#define TX_PIN 6
#define RX_PIN 5
int numbers;

SoftwareSerial mySerial(RX_PIN, TX_PIN);
Adafruit_Thermal printer(&mySerial);

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
  
};
byte rowPins[ROWS] = {11,12,A0,A1};

byte colPins[COLS] = {A2,A3,A4,A5};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,ROWS,COLS);

void setup() {
  delay(500);
  mySerial.begin(9600);
  printer.begin();  
  lcd.setCursor(0,0);
  lcd.print("THERMAL_PRINTER");
  delay(2000);
  lcd.clear();

 
}

void loop() {
  char key = customKeypad.getKey();
 
  if (key != NO_KEY)
  {
    numbers =(key);
    if(key == '*')
    {
      printer.setDefault();
      lcd.clear();
    }
    else if (key == '#')
    {
      lcd.setCursor(0,1);
        printer.justify('L');
  printer.println("***  HAPPY ***\n");
  printer.justify('C');
  printer.setSize('M');        // Set type size, accepts 'S', 'M', 'L'
  printer.println("LATE COMMERS");
  printer.boldOn();
  printer.setSize('M');
  printer.println(numbers);
  printer.boldOff();
  printer.justify('C');
  printer.setSize('S');
  printer.println("***  HAVE A NICE DAY  ***");
  printer.justify('C');
  printer.print("DATE:24/12/2019\t");
  printer.println("TIME: 00:00");
  printer.println("TODAY: MONDAY");   
  printer.write(10);
  printer.write(10);
  printer.write(10);
    }
    else
    {
      lcd.print(key);
      numbers = (key);
    }
  }
  


  
  

}
