#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include <Wire.h>
#include <Keypad.h>
#include "RTClib.h"
#define TX_PIN 6
#define RX_PIN 5

const int buttonPin = 3; 
int buttonState = 0; 


const byte ROWS = 4;
const byte COLS = 3;
int firstvariable ;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {7, 8, 9, 10}; 
byte colPins[COLS] = {11, 12, A0}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 


SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial); 

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
    while (!Serial);
    Serial.begin(9600);
    mySerial.begin(9600);  
   printer.begin();
    pinMode(buttonPin, INPUT);
    
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
   // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
   // rtc.adjust(DateTime(2019, 12, 24, 1, 0, 0));
  }
}

void loop() {
  DateTime now = rtc.now();

    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    delay(1000);

 buttonState = digitalRead(buttonPin);
 char customKey = customKeypad.getKey();
  

  //switch(key1){
    //case NO_KEY:
    //break;
    //case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
    //Serial.print(key1);
   // firstvariable = firstvariable*10+key1-'0';
 //   break;


//    case'#':
//    Serial.println();
//    Serial.print(firstvariable);
  //  }

    
    if(customKey == '#')
    {
    printer.begin();
    printer.justify('C');
    printer.println("HAve A Nice Day \n");
    printer.justify('C');
    printer.setSize('M');        // Set type size, accepts 'S', 'M', 'L'
    printer.println("LATE COMMERS");
    printer.boldOn();
    printer.setSize('M');
    printer.println(firstvariable);
    printer.boldOff();
    printer.justify('C');
    printer.setSize('S');
    printer.println("***  HAVE A NICE DAY  ***");
    printer.justify('C');
    printer.println("DATE :");
    printer.print(now.year(), DEC);
    printer.print('/');
    printer.print(now.month(), DEC);
    printer.print('/');
    printer.print(now.day(), DEC);
    printer.print("\n");
    printer.println("TIME:");
    printer.print(now.hour(), DEC);
    printer.print(':');
    printer.print(now.minute(), DEC);
    printer.print(':');
    printer.print(now.second(), DEC);
    printer.print("\n");    
    printer.println("TODAY:");
    printer.print(daysOfTheWeek[now.dayOfTheWeek()]);   
    printer.write(10);
    printer.write(10);


 
}
}
