#include "driver.h"

Driver::Driver(Engine * e){
  this -> engine = e;
}

void Driver::runMotor(int speed_){

   if (speed_ < 0) {
      speed_ = speed_ * -1;
       
      engine->go_forward(  map(speed_, 0, 100, 0, 1020));
      //req = "forward";

    } else if (speed_ == 0) {
      engine->hard_stop();
      //req = "stop";
    }

    else {
      engine->go_back( map(speed_, 0, 100, 0, 1020)); 
    }
}

