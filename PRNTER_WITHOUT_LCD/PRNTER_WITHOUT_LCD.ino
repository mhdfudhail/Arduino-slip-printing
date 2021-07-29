#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"

#define TX_PIN 6
#define RX_PIN 5

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
SoftwareSerial Serial1(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial1);

SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial); 

#include <Wire.h>
#include "RTClib.h"

const char* NAME;
const char* ID;

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
byte rowPins[ROWS] = {8, 9, 10, 11};
byte colPins[COLS] = {12, A0, A1, A2}; 

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

String ch="111111222233334444555566667777788889999900";


String number="";
String msg="";
String ma ="";
String Astate = "";

void setup() {
   Serial.begin(9600);
   mySerial.begin(9600);

    while (!Serial);

    mySerial.begin(9600);  
   printer.begin();
    
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

  
  // set the data rate for the sensor serial port
  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");

  delay(2000);

}




void loop() {

   getFingerprintIDez();
  delay (50);
  if( finger.fingerID  ){

  
  Serial.println("Initilising ...");
  delay(400);
 delay(2000);
  
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

  Serial.print("AT+CMGS=\" ");

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
        
      }
    }
  }  
  
  delay(1000);
  
  }
  
  alfakey();
}









void alfakey()
{
 int x=0,y=0;
 int num=0;
  while(1)
  {
    
    char key=customKeypad.getKey();
    if(key)
    {
       if(key=='1')
       {
         num=0;
         
         for(int i=0;i<3000;i++)
         { 
         
          char key=customKeypad.getKey();
          if(key=='1')
          {
           num++;
           if(num>5)
           num=0;
         
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
         
         for(int i=0;i<3000;i++)
         { 
        
          char key=customKeypad.getKey();
          if(key=='2')
          {
           num++;
           if(num>9)
           num=6;
     
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
       
         for(int i=0;i<3000;i++)
         { 
      
          char key=customKeypad.getKey();
          if(key=='3')
          {
           num++;
           if(num>13)
           num=10;
       
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

         for(int i=0;i<3000;i++)
         { 
       
          char key=customKeypad.getKey();
          if(key=='4')
          {
           num++;
           if(num>17)
           num=14;
      
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
  
         for(int i=0;i<3000;i++)
         { 
  
          char key=customKeypad.getKey();
          if(key=='5')
          {
           num++;
           if(num>21)
           num=18;
       
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

         for(int i=0;i<3000;i++)
         { 
       
          char key=customKeypad.getKey();
          if(key=='6')
          {
           num++;
           if(num>25)
           num=22;
    
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
      
         for(int i=0;i<3000;i++)
         { 
        
          char key=customKeypad.getKey();
          if(key=='7')
          {
           num++;
           if(num>30)
           num=26;
      
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
       
         for(int i=0;i<3000;i++)
         { 
       
          char key=customKeypad.getKey();
          if(key=='8')
          {
           num++;
           if(num>34)
           num=31;
         
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
    
         for(int i=0;i<3000;i++)
         { 
    
          char key=customKeypad.getKey();
          if(key=='9')
          {
           num++;
           if(num>39)
           num=35;
          
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
   
         for(int i=0;i<3000;i++)
         { 
         
          char key=customKeypad.getKey();
          if(key=='0')
          {
           num++;
           if(num>41)
           num=40;
        
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
         
         for(int i=0;i<3000;i++)
         { 
     
          char key=customKeypad.getKey();
          if(key=='B')
          {
           num++;
           if(num>41)
           num=40;
          
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
      
         for(int i=0;i<3000;i++)
         { 
          char key=customKeypad.getKey();
          if(key=='C')
          {
           num++;
           if(num>41)
           num=40;
  
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
         
         for(int i=0;i<3000;i++)
         { 
     
          char key=customKeypad.getKey();
          if(key=='*')
          {
           num++;
           if(num>41)
           num=40;
           
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

        else if(key=='A')
        {
       
           DateTime now = rtc.now();
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
          
          
          Serial.print(msg);
         
          delay(5000);
      
          delay(1000);
          number="";
          msg ="";
          Astate="";
          break;
          Serial.write(26);
          Serial.println(msg);
          
          return;
          
        } 
      }
  }
 
  

}
