#include "Adafruit_Thermal.h"
#include <Adafruit_Fingerprint.h>

#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial1);

#define TX_PIN 6
#define RX_PIN 5

SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial);

const char* NAME;
const char* ID;

void setup() {
   
   Serial.begin(9600); 
 Serial1.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) {
      delay(1);
    }
  }

  
  finger.getTemplateCount();
  Serial.print("Sensor contains "); 
  Serial.print(finger.templateCount); 
  Serial.println(" templates");
  Serial.println("Waiting for valid finger...");

}

void loop() { 
  
  getFingerprintIDez();
  if (finger.fingerID == 1) {

    Serial.print("!!--");
    Serial.println(finger.fingerID);
    NAME = "AAA";
    ID = "1";
    if (finger.confidence >= 60) {
      Serial.print("Attendace Marked for ");
      Serial.println(NAME);
      
      // digital write - open the door
    }

  }

  if (finger.fingerID == 2 ) {
    Serial.print("!!--");
    Serial.println(finger.fingerID);
   
    NAME = "BBB";
    ID = "11";
    Serial.print(finger.confidence); 
    Serial.print("Attendace Marked for "); 
    Serial.println(NAME);
    
        mySerial.begin(9600);  
        printer.begin();        // Init printer (same regardless of serial type)
        printer.justify('C');
        printer.println("HAve A Nice Day \n");
        printer.justify('C');
        printer.setSize('M');        // Set type size, accepts 'S', 'M', 'L'
        printer.println("LATE COMMERS");
        printer.boldOn();
        printer.setSize('M');
        printer.println(NAME);
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
        
    
    //don't ned to run this at full speed.
 
  }
 
  finger.fingerID = 0;
 
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
 
  return finger.fingerID;
 
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID; 
}
