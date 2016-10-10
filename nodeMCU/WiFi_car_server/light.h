#ifndef LIGHT_H
#define LIGHT_H
#include <Arduino.h>
class  Light {
  int ledPIN;
  
  public:
  Light(int _ledPIN);
  void turnON_half();
  void turnON_max();
  void turnOFF();
  
};


#endif
