#ifndef LIGHT_H
#define LIGHT_H
#include <Arduino.h>

enum State {ON, OFF};

class  Light {
  int ledPIN;
  State lightStatus      = OFF;
  State lightExtraStatus = OFF;
  int halfPower = 100;
  public:
  Light(int _ledPIN);
  void turnON_half();
  void turnOFF_half();
  void turnON_max();
  void turnOFF();
  
};


#endif
