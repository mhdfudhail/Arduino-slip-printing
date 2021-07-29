#include<LiquidCrystal.h>
LiquidCrystal lcd(0,1,2,3,4,7);
#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 6
#define RX_PIN 5


SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial); 

#include <Wire.h>
#include "RTClib.h"



RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {8, 9, 10, 11}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {12, A0, A1, A2}; //connect to the column pinouts of the keypad
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

String ch="1,1,,,2,2,3,3,4,4,5,5,6,6,7,,7,8,8,9,9,,0,";


String number="";
String msg="";
String str_sms="";
String str1="";
String ma ="";
String Astate = "";

int i=0,temp=0;
int sms_flag=0;
char sms_num[3];

int temp1=0;


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

   lcd.begin(16,2);
   lcd.print("System Ready");
  delay(2000);

}

void loop() {
  lcd.clear();
  lcd.print("Initilising...");
  Serial.println("Initilising ...");
  delay(400);
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
    Serial.println();
    if(now.hour() >= 9 || now.minute()>=10)
    {
      Astate = ("WITHOUT ATTANDANCE");
    }
    else
    {
      Astate =("WITH ATTANDANCE");
      
    }
 
    delay(1000);
  //
  lcd.print("Enter semester:");
  lcd.setCursor(0,1);
  Serial.print("AT+CMGS=\" ");
  lcd.print("AT+CMGS=\" ");
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
  lcd.clear();
  lcd.print("PRESS >D< ");
  lcd.setCursor(0,1);
  lcd.print("TO Print ");
  delay(1000);
  lcd.clear();
  lcd.print("Enter>Your>Numbers");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  alfakey();
}
void alfakey()
{
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
           delay(200);
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
           delay(200);
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
           delay(200);
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
           delay(200);
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
           delay(200);
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
           delay(200);
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
           delay(200);
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
           delay(200);
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
           delay(200);
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
           delay(200);
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

        else if(key=='A')
        {
          Serial.print(msg);
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
          lcd.clear();
          lcd.print("Sending SMS....");
          Serial.print(msg);
          lcd.setCursor(0,1);
          lcd.print(msg);
          delay(5000);
          lcd.clear();
          lcd.print("SMS Sent to");
          delay(2000);
          number="";
          msg ="";
          break;
          Serial.write(26);
          Serial.println(msg);
          
          return;
        } 
      }
  }
 
  

}
