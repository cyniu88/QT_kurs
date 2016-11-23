#include "driver.h"

Driver::Driver(Engine * e) {
  this -> engine = e;
}

void Driver::runMotor(int speed_) {
  if (speed_ < 0) {
    engine->go_forward(  map(speed_, -100, 0,PWMRANGE  , 0));
  }
  else if (speed_ == 0) {
    engine->hard_stop();
  }
  else {
    engine->go_back( map(speed_, 0, 100, 0, PWMRANGE));
  }
}

