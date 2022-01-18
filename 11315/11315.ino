#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 5); //Rx,Tx
char data ;
int s ;
int red1 = 4 ;
int yellow1 = 3 ;
int green1 =7  ;
int white4 = 8 ;
int white = 12 ;
int red2 = 9 ;
int yellow2 = 10 ;
int green2 = 11;
int counter =0 ;
int white1= 13 ;
#define trig2 A2
#define echo1 A1
#define trig1 A0
#define echo2 A3
int d=0 ;
long t=0 ;
int d1=0 ;
long t1=0 ;
int light = 0 ;
void setup()
{  
Serial.begin(9600);
  mySerial.begin(9600);

pinMode(white4, OUTPUT);
pinMode(white1,OUTPUT);
pinMode(white, OUTPUT);
  pinMode(trig1, OUTPUT);
pinMode(echo1, INPUT);
pinMode(red1, OUTPUT);
pinMode(yellow1, OUTPUT);
pinMode(green1, OUTPUT);
pinMode(red2, OUTPUT);
pinMode(yellow2, OUTPUT);
pinMode(green2, OUTPUT);
pinMode(trig2, OUTPUT);
pinMode(echo2, INPUT);

}
void loop()

{
light =analogRead(A4);
digitalWrite(trig1, LOW);

delayMicroseconds(2);
digitalWrite(trig1, HIGH);

delayMicroseconds(10);
digitalWrite(trig1, LOW);


t=pulseIn(echo1,HIGH);
d=t/57 ;
digitalWrite(trig2, LOW);
delayMicroseconds(2);
digitalWrite(trig2, HIGH);
delayMicroseconds(10);
digitalWrite(trig2, LOW);

t1=pulseIn(echo2,HIGH);

d1=t1/57 ;


  if (1)
{

    char data = mySerial.read();
    Serial.print(data);
    if (data == '0'|| s!=0){
   Serial.print("manual mode");
s=1; 
delay(500);

Serial.println(); 



    if (data == '1') {
digitalWrite(white4, HIGH);
digitalWrite(white, HIGH);
digitalWrite(white1,HIGH);
digitalWrite(green1, LOW);
digitalWrite(red2, LOW);
digitalWrite(red1, HIGH);
digitalWrite(green2, HIGH);
delay(500);
digitalWrite(red1, LOW);
digitalWrite(green2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
delay(500);
digitalWrite(yellow1, LOW);
digitalWrite(green1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(yellow2, LOW);
delay(500);
      
    }
else if (data == '2') {
digitalWrite(white4, HIGH);
digitalWrite(white, LOW);
digitalWrite(white1,LOW);
digitalWrite(green1, LOW);
digitalWrite(red2, LOW);
digitalWrite(red1, HIGH);
digitalWrite(green2, HIGH);
delay(500);
digitalWrite(red1, LOW);
digitalWrite(green2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
delay(500);
digitalWrite(yellow1, LOW);
digitalWrite(green1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(yellow2, LOW);
delay(500);
      
    }
else if (data == '3') {
digitalWrite(white4, LOW);
digitalWrite(white, LOW);
digitalWrite(white1,LOW);
digitalWrite(green1, LOW);
digitalWrite(red2, LOW);
digitalWrite(red1, HIGH);
digitalWrite(green2, HIGH);
delay(500);
digitalWrite(red1, LOW);
digitalWrite(green2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
delay(500);
digitalWrite(yellow1, LOW);
digitalWrite(green1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(yellow2, LOW);
delay(500);
      
    }



    else if (data == '4') {
      digitalWrite(white4, HIGH);
digitalWrite(white, HIGH);
 digitalWrite(white1,LOW);
digitalWrite(green1, LOW);
digitalWrite(red1, HIGH);

digitalWrite(yellow1, LOW);
digitalWrite(red2, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(green2, HIGH);
 delay(500);
    }

    else if (data == '5') {
      digitalWrite(white4, LOW);
digitalWrite(white, LOW);
 digitalWrite(white1,LOW);
digitalWrite(green1, LOW);
digitalWrite(red1, HIGH);

digitalWrite(yellow1, LOW);
digitalWrite(red2, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(green2, HIGH);
 delay(500);
    }
    else if (data == '7') {digitalWrite(white4, LOW);
digitalWrite(white, LOW);
 digitalWrite(white1,LOW);
digitalWrite(green1, HIGH);
digitalWrite(red1, LOW);

digitalWrite(yellow1, LOW);
digitalWrite(red2, HIGH);
digitalWrite(yellow2, LOW);
digitalWrite(green2, LOW);
 delay(500);
      
    }
 else if (data == '6') {
digitalWrite(white4, HIGH);
digitalWrite(white, LOW);
 digitalWrite(white1,HIGH);
   
digitalWrite(green1, HIGH);
digitalWrite(red1, LOW);

digitalWrite(yellow1, LOW);
digitalWrite(red2, HIGH);
digitalWrite(yellow2, LOW);
digitalWrite(green2, LOW);
 delay(500);
   
    }





 
  

if (data == 'E') {

s=0 ;
Serial.print("shifting"); 

    }
 mySerial.write(Serial.read());
}
  
  
  
else if (s!=1)
{Serial.print("Automatic mode"); 

Serial.println(); 


 if (light <200 &d<100 &d1<100 ) //1
{digitalWrite(white4, HIGH);
digitalWrite(white, HIGH);
digitalWrite(white1,HIGH);
}
else if (light <200& d>100 &d1<100 ) //2
{digitalWrite(white4, HIGH);
digitalWrite(white, HIGH);
 digitalWrite(white1,LOW);}
else if(light >200 ) //3
{digitalWrite(white4, LOW);
digitalWrite(white, LOW);
 digitalWrite(white1,LOW);}
else if(light <200& d>100 &d1>100 ) //4
{digitalWrite(white4, HIGH);
digitalWrite(white, LOW);
 digitalWrite(white1,LOW);}
else if (light <200& d<100 &d1>100 ) //5
{digitalWrite(white4, HIGH);
digitalWrite(white, LOW);
 digitalWrite(white1,HIGH);
}



 else 
{digitalWrite(white4, HIGH);
digitalWrite(white, LOW);
digitalWrite(white1,LOW);}

if(d>50&d1<50 ) //6
{digitalWrite(green1, LOW);
digitalWrite(red1, HIGH);

digitalWrite(yellow1, LOW);
digitalWrite(red2, LOW);
digitalWrite(yellow2, LOW);
digitalWrite(green2, HIGH);
 delay(500);}


else if(d<50& d1>50 ) //7
{digitalWrite(green1, HIGH);
digitalWrite(red1, LOW);
digitalWrite(yellow1, LOW);
digitalWrite(red2, HIGH);
digitalWrite(yellow2, LOW);
digitalWrite(green2, LOW);

delay(500);
}
else{
digitalWrite(green1, LOW);
digitalWrite(red2, LOW);
digitalWrite(red1, HIGH);
digitalWrite(green2, HIGH);
delay(500);
digitalWrite(red1, LOW);
digitalWrite(green2, LOW);
digitalWrite(yellow1, HIGH);
digitalWrite(yellow2, HIGH);
delay(500);
digitalWrite(yellow1, LOW);
digitalWrite(green1, HIGH);
digitalWrite(red2, HIGH);
digitalWrite(yellow2, LOW);
delay(500);

 }
}
Serial.print("distance road 2:");
Serial.print(d1);
Serial.print("       distance road 1:"); 
Serial.print(d);
Serial.print("       light:");
Serial.println(light); 

Serial.print("s=");
 Serial.println(s);
 Serial.print("data=");
 Serial.println(data);
 

 
  }}
