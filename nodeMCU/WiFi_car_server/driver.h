#ifndef DRIVER_H
#define DRIVER_H

#include "engine.h"
#include "mytype.h"

 enum direction_STATE {
  High = 0,
  Zero = 1,
  Low  = 2,
 };
class Driver
{
  direction_STATE mainSTATE = Zero;
  Engine *engine;
  
  public:
  Driver(Engine * e);
  void runMotor(int speed_);
};

#endif
