#ifndef STOP_LIGHT_H
#define STOP_LIGHT_H
#include "light.h"

class StopLight{
  Light  *lightBack;
  int stopLedTimer;
  int stopLedTimerBase;
  int lastSpeed         = 0;
  public:
  StopLight(Light *backL,int stopLedTimer );
  void handle(int speed_);
};
#endif

