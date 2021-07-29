#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 6
#define RX_PIN 5

SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial);   

void setup() {
  
  mySerial.begin(9600);  
  printer.begin();        // Init printer (same regardless of serial type)
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
  printer.print("DATE:24/12/2019\t");
  printer.println("TIME: 00:00");
  printer.println("TODAY: MONDAY");   
  printer.write(10);
  printer.write(10);
  printer.write(10);
  
}

void loop() {
 
}
