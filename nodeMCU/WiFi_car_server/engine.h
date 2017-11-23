#ifndef ENGINE_H
#define ENGINE_H
#include <Arduino.h>
#include "PCF8574.h"

class Engine {
    int pwm;
    int BN1;
    int BN2;
    PCF8574 pcf8574;
    public:
    Engine();
    void init(int pwm, int BN1, int BN2);
    void go_forward(int power);
    void go_back   (int power);
    void hard_stop();
};
#endif
