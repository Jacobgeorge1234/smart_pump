#include <Adafruit_SSD1306.h>


#include<Wire.h>
#include<Adafruit_GFX.h>
#include <EEPROM.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
float tal,pal;
int val;
int sal,a=0,b=0;
int address=0,n;
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 Serial.begin(9600); 
  display.setTextSize(1.75);
  display.setTextColor(WHITE);
pinMode(7,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);
pinMode(9, OUTPUT);
}

void loop() {
  val = digitalRead(7);
  sal = digitalRead(6);
   tal = analogRead(A0);
  pal= tal*(5.0/1023.0);
  Serial.println(sal);

 if((val==LOW)&&(sal==LOW)){
    digitalWrite(9,LOW);
 }
else{
   if (val == LOW){
    b=0;
    
a=1;
  EEPROM.put(address,a);
  }    
  if(sal == LOW){
    b++;
    if(b==1){
      a=0;
       EEPROM.write(address, 0);
    }
    }
     EEPROM.get(address,a);
    if(a==1){
 
 digitalWrite(9,HIGH);
     display.clearDisplay();
     display.setCursor(0,0);
     display.print("PUMPING");
      display.setCursor(70,0);
   display.println("theodore");
   display.setCursor(70,10);
   display.println("melschire");
  display.display();
     
     
    /*  if((pal>1.80)&&(pal<3.00)){
         digitalWrite(13,HIGH);
      }
      else{ digitalWrite(13,LOW);
      }*/
    }
    else{
   display.clearDisplay();
   display.setCursor(0,0);
     display.print("FULL");
  display.setCursor(70,0);
   display.println("theodore");
   display.setCursor(70,10);
   display.println("melschire");
  display.display();
       digitalWrite(9,LOW);
    }
}
Serial.println(a);
//Serial.println(pal);
/*if(sal==HIGH){
  a=0;
 digitalWrite(13,LOW);*/

  }
/*
if(sal == HIGH){
  b++;
}
if(b==1){ 
   digitalWrite(13,LOW);
   a=0;
}
}*/
