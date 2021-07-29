#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 18
#define RX_PIN 19


SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial); 

#include <Adafruit_Fingerprint.h>

#include <SoftwareSerial.h>
SoftwareSerial SerialA(10, 11);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&SerialA);

#include <Wire.h>
#include "RTClib.h"



RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#include <Keypad.h>
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {49, 47, 45, 43};
byte colPins[COLS] = {39, 37, 35, 33}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

String ch="111111222233334444555566667777788889999900";


String number="";
String msg="";
String ma ="";
String Astate = "";
String Name = "";
const char * ID;

void setup() {
   Serial.begin(9600);
   mySerial.begin(9600);
   SerialA.begin(9600);
    while (!Serial);
    
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
   //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2020, 1, 18, 1, 0, 0));
  }

   lcd.begin(16,2);
   lcd.print("System Ready");
  delay(2000);


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
   delay(50);
   
  lcd.clear();
  lcd.print("Initilising...");
  Serial.println("Initilising ...");
  delay(100);
  lcd.clear();
  lcd.print("After Enter No.");
  lcd.setCursor(0,1);
  lcd.print("Press D       ");
  delay(2000);
  lcd.clear();
  //

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
    if(now.hour() >= 12)
    {
      Serial.print("PM");
      ma = ("PM");
    }
    else 
    {
      Serial.print("AM");
      ma = ("AM");
    }
    
 
    delay(1000);
  // 
  lcd.setCursor(0,0);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  lcd.print(ma);
  
  Serial.print("A=\" ");
  lcd.setCursor(0,1);
  lcd.print("Enter sem:");

  while(1)
  {
   
    char key=customKeypad.getKey();
    if(key)
    {
      if(key=='D')
      {
        number+='"';
        Serial.println("\"");
        break;
      }

      else
      {
        number+=key;
        Serial.print(key);
        lcd.print(key);
      }
    }
  }  


  delay(1000);
  lcd.clear();
  lcd.print("Enter > Numbers");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
 
 


 int x=0,y=0;
 int num=0;
  while(1)
  {
    lcd.cursor();
    char key=customKeypad.getKey();
    if(key)
    {
       if(key=='1')
       {
         num=0;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='1')
          {
           num++;
           if(num>5)
           num=0;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
         if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
        
       else if(key=='2')
       {
         num=6;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='2')
          {
           num++;
           if(num>9)
           num=6;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
       else if(key=='3')
       {
         num=10;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='3')
          {
           num++;
           if(num>13)
           num=10;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
       else if(key=='4')
       {
         num=14;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='4')
          {
           num++;
           if(num>17)
           num=14;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
              else if(key=='5')
       {
         num=18;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='5')
          {
           num++;
           if(num>21)
           num=18;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
        else if(key=='6')
       {
         num=22;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='6')
          {
           num++;
           if(num>25)
           num=22;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
       else if(key=='7')
       {
         num=26;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='7')
          {
           num++;
           if(num>30)
           num=26;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
       else if(key=='8')
       {
         num=31;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='8')
          {
           num++;
           if(num>34)
           num=31;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
       else if(key=='9')
       {
         num=35;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='9')
          {
           num++;
           if(num>39)
           num=35;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];
        }
        else if(key=='0')
       {
         num=40;
         lcd.setCursor(x,y);
         lcd.print(ch[num]);
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='0')
          {
           num++;
           if(num>41)
           num=40;
           lcd.setCursor(x,y);
           lcd.print(ch[num]);
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=ch[num];

        }

        else if(key=='B')
       {
         num=40;
         lcd.setCursor(x,y);
         lcd.print("B");
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='B')
          {
           num++;
           if(num>41)
           num=40;
           lcd.setCursor(x,y);
           lcd.print("B");
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         Astate="WITH ATTENDANCE";

        }

       else if(key=='C')
       {
         num=40;
         lcd.setCursor(x,y);
         lcd.print("C");
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='C')
          {
           num++;
           if(num>41)
           num=40;
           lcd.setCursor(x,y);
           lcd.print("C");
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         Astate="WITHOUT ATTENDANCE";

        }
        
        
        else if(key== '*')
        {
                   num=40;
         lcd.setCursor(x,y);
         lcd.print(",");
         for(int i=0;i<3000;i++)
         { 
          lcd.noCursor();
          char key=customKeypad.getKey();
          if(key=='*')
          {
           num++;
           if(num>41)
           num=40;
           lcd.setCursor(x,y);
           lcd.print(",");
           i=0;
           delay(50);
          } 
         }
         x++;
          if(x>15)
         {
           x=0;
           y++;
           y%=2;
         }
         msg+=",";
      
           }
          else if(key== 'A')
           {
              getFingerprintIDez();
              delay(200);
              
              
              
            } 
            else if(key== '#')
           {
            
              return;
              
              
            }   

    }
   }
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
  Serial.print(" with confidence of ");
  
            Serial.print(msg);
           DateTime now = rtc.now();
          lcd.clear();
          lcd.print("Printing....");
          lcd.setCursor(0,1);
          lcd.print(msg);
          printer.begin();
          printer.justify('C');
          printer.boldOn();
          printer.setSize('S');        // Set type size, accepts 'S', 'M', 'L'
          printer.println(" \n DEPARTMENT OF ");
          printer.println("ELECTRICAL & ELECTRONICS ");
          printer.println("ENGINEERING \n");
          printer.boldOff();
          printer.setSize('M'); 
          printer.println("_LATE COMERS_");
          printer.setSize('S'); 
          printer.print("SEMESTER: ");
          printer.println(number);
          printer.print("\n");
          printer.justify('C');
          printer.boldOn();
          printer.setSize('S');
          printer.println(msg); 
          printer.print("\n");
          printer.boldOff();
          printer.justify('C');
          printer.setSize('S');
          printer.println(Astate);
          printer.println("***  HAVE A NICE DAY  ***");
          printer.print("\n");
          printer.justify('C');
          printer.setSize('S');
          printer.print(Name);
          printer.print("\n");  
          printer.justify('C');
          printer.print("DATE:");
          printer.print(now.day(), DEC);
          printer.print('/');
          printer.print(now.month(), DEC);
          printer.print('/');
          printer.print(now.year(), DEC);
          printer.print("\n");
          printer.print("TIME:");
          printer.print(now.hour(), DEC);
          printer.print(':');
          printer.print(now.minute(), DEC);
          printer.print(':');
          printer.print(now.second(), DEC);
          printer.print(" ");
          printer.print(ma);
          printer.print("\n");       
          printer.print("TODAY:");
          printer.print(daysOfTheWeek[now.dayOfTheWeek()]);   
          printer.write(10);
          printer.write(10);
          printer.write(10);
          printer.write(10);
          printer.write(10);
          printer.write(10);
          
          number="";
          msg ="";
          Astate="";
          finger.fingerID = 0;
          
          Serial.print(msg);
          Serial.print(Name);
          
          delay(4000);
          lcd.clear();
          lcd.print("press # to clear");
          delay(1000);

          Serial.write(26);
          Serial.println(msg); 
           
}
