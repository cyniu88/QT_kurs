#include "driver.h"

Driver::Driver(Engine * e) {
  this -> engine = e;
}

void Driver::runMotor(int speed_) {
  if (speed_ < 0) {
    if (mainSTATE != High){
      engine->hard_stop();
      mainSTATE = High;
    }
    engine->go_forward(  map(speed_, -100, 0,PWMRANGE  , 0));
  }
  else if (speed_ == 0) {
    if (mainSTATE != Zero){
      mainSTATE =Zero;
    }
    engine->hard_stop();
  }
  else {
    if (mainSTATE != Low) {
      engine->hard_stop();
      mainSTATE= Low;
    }
    engine->go_back( map(speed_, 0, 100, 0, PWMRANGE));
  }
}

