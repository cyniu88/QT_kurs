#include "stopLight.h"

StopLight::StopLight(Light *backL, int stopLedTimer){
  this -> lightBack = backL;
  this -> stopLedTimerBase = stopLedTimer;
}

void StopLight::handle(int speed_){
   if (speed_ < 0) {
      speed_ = speed_ * -1;
   }
   if (speed_ < lastSpeed)
      {
        lightBack -> maximal();
      }
      else if (speed_ > lastSpeed) {
        lightBack -> maximalEnd();
      }
      else if (speed_ == lastSpeed){
        if ( stopLedTimer == 0 ){
          lightBack -> maximalEnd();
          stopLedTimer = stopLedTimerBase;
        }
        else{
          --stopLedTimer;
        }
      }
      lastSpeed = speed_;
/// light ///////////////
}

