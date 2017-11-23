#include "engine.h"

Engine::Engine():pcf8574(0x20){}
void Engine::init(int pwm, int BN1, int BN2){
  this->pwm = pwm;
  this->BN1 = BN1;
  this->BN2 = BN2;
  pinMode(pwm,OUTPUT);
  analogWrite(pwm,0);
  pcf8574.digitalWrite(BN1, LOW);
  pcf8574.digitalWrite(BN2, LOW);
}

void Engine::go_back(int power){
    pcf8574.digitalWrite(BN1, HIGH );
    pcf8574.digitalWrite(BN2, LOW);
    analogWrite (pwm, power);
}

void Engine::go_forward(int power){
    pcf8574.digitalWrite(BN1, LOW);
    pcf8574.digitalWrite(BN2, HIGH );
    analogWrite (pwm, power);
}
 void Engine::hard_stop (){
    analogWrite (pwm,0);
    pcf8574.digitalWrite(BN2,LOW);
    pcf8574.digitalWrite(BN1,LOW);
 }

