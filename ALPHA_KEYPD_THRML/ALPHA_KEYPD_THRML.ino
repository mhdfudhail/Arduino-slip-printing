#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 6
#define RX_PIN 5

SoftwareSerial mySerial(RX_PIN, TX_PIN); 
Adafruit_Thermal printer(&mySerial);   

#include<LiquidCrystal.h>
LiquidCrystal lcd(0,1,2,3,4,7);
String number="";
String msg="";
String str_sms="";
String str1="";
int ring=0;
int i=0,temp=0;
int sms_flag=0;
char sms_num[3];

int temp1=0;
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

String ch="1,.?!@2abc3def4ghi5jkl6mno7pqrs8tuv9wxyz0 ";
void setup() {
   Serial.begin(9600);
   mySerial.begin(9600);

   lcd.begin(16,2);
   lcd.print("System Ready");
  delay(2000);

}

void loop() {
  lcd.clear();
  lcd.print("Initilising...");
  Serial.println("Initilising SMS");
  delay(400);
  lcd.clear();
  lcd.print("After Enter No.");
  lcd.setCursor(0,1);
  lcd.print("Press D       ");
  delay(2000);
  lcd.clear();
  //
  //TIME
  //DATE
  //DAY
  //
  lcd.print("Enter semester:");
  lcd.setCursor(0,1);
  Serial.print("AT+CMGS=\" ");
  while(1)
  {
   
    char key=customKeypad.getKey();
    if(key)
    {
      if(key=='D')
      {
        //number+='"';
        Serial.println("\"");
        break;
      }
      else
      {
        //number+=key;
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
           delay(100);
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
        else if(key=='D')
        {
          printer.begin();        // Init printer (same regardless of serial type)
          printer.justify('C');
          printer.println("HAve A Nice Day \n");
          printer.justify('C');
          printer.setSize('M');        // Set type size, accepts 'S', 'M', 'L'
          printer.println("LATE COMMERS");
          printer.boldOn();
          printer.setSize('M');
          printer.println(msg);
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
          break;
          Serial.write(26);
          Serial.println(msg);
          return;
        } 
      }
  }
 
  

}
