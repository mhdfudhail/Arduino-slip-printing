#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#include <Wire.h>
#include "RTClib.h"
#define TX_PIN 6
#define RX_PIN 5

const int buttonPin = 2; 
int buttonState = 0; 

SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial); 

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup() {
  while (!Serial);

    mySerial.begin(9600);  
   printer.begin();
    pinMode(buttonPin, INPUT);
    
  Serial.begin(57600);
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

     if (buttonState == HIGH)
     {
      printer.begin();
       printer.justify('C');
  printer.println("HAve A Nice Day \n");
  printer.justify('C');
  printer.setSize('M');        // Set type size, accepts 'S', 'M', 'L'
  printer.println("LATE COMMERS");
  printer.boldOn();
  printer.setSize('M');
  printer.println("001\n");
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
  printer.write(10);
    printer.write(10);
  printer.write(10);
  printer.write(10);

 }
   
}
