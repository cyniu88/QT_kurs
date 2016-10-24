#include "engine.h"

void Engine::init(int pwm, int BN1, int BN2){
  this->pwm = pwm;
  this->BN1 = BN1;
  this->BN2 = BN2;
  pinMode(pwm,OUTPUT);
  pinMode(BN1,OUTPUT);
  pinMode(BN2,OUTPUT);
  digitalWrite(BN1, LOW);
  digitalWrite(BN2, LOW);
}

void Engine::go_back(int power){

    digitalWrite(BN1, HIGH );
    digitalWrite(BN2, LOW);
    analogWrite (pwm, power);
}

void Engine::go_forward(int power){

    digitalWrite(BN1, LOW);
    digitalWrite(BN2, HIGH );
    analogWrite (pwm, power);
}
 void Engine::hard_stop (){
    analogWrite (pwm,0);
    digitalWrite(BN2,LOW);
    digitalWrite(BN1,LOW);
 }

