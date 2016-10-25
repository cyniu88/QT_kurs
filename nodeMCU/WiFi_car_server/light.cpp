#include "light.h"


Light::Light(int _ledPIN)
    : ledPIN(_ledPIN)
{
    pinMode(ledPIN, OUTPUT);
    digitalWrite(ledPIN, LOW);
}

void Light::turnON_half()
{
    if (lightStatus == OFF  && lightExtraStatus == OFF){
      analogWrite(ledPIN, halfPower);
      lightStatus = ON;
    }
}
void Light::turnOFF_half(){
   if (lightExtraStatus == ON ){
      if (lightStatus == ON){
        analogWrite(ledPIN, halfPower);
      }
      else{
        analogWrite(ledPIN, 0);
      }
    lightExtraStatus = OFF;
   }
}
void Light::turnON_max()
{      if (lightExtraStatus == OFF) {
        analogWrite(ledPIN, 1023);
        lightExtraStatus = ON; 
      }
}
void Light::turnOFF()
{
   if (lightStatus == ON && lightExtraStatus == OFF){
     analogWrite(ledPIN, 0);
     lightStatus = OFF;
   }
}

