#include "light.h"


Light::Light(int _ledPIN)
    : ledPIN(_ledPIN)
{
    pinMode(ledPIN, OUTPUT);
    digitalWrite(ledPIN, LOW);
}

void Light::turnON()
{
    if (lightStatus == OFF  && lightExtraStatus == OFF){
      analogWrite(ledPIN, halfPower);
      lightStatus = ON;
    }
}
void Light::turnOFF(){
   if (lightExtraStatus == OFF ){
      if (lightStatus == ON){
         
        analogWrite(ledPIN, 0);
        lightStatus = OFF;
      }
    
   }
}
void Light::maximal()
{      if (lightExtraStatus == OFF) {
        analogWrite(ledPIN, 1023);
        lightExtraStatus = ON; 
      }
}
void Light::maximalEnd()
{
   if (lightStatus == ON && lightExtraStatus == ON){
     analogWrite(ledPIN, halfPower);
     lightExtraStatus = OFF;
   }
   else if (lightStatus == OFF && lightExtraStatus == ON){
      analogWrite(ledPIN, 0);
     lightExtraStatus = OFF;
   }
}

