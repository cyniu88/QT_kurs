#ifndef DRIVER_H
#define DRIVER_H

#include "engine.h"
#include "mytype.h"

class Driver
{
  Engine *engine;
  public:
  Driver(Engine * e);
  void runMotor(int speed_);
};

#endif
