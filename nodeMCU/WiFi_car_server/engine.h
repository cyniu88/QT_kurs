#ifndef ENGINE_H
#define ENGINE_H
#include <Arduino.h>
class Engine {
    int pwm;
    int BN1;
    int BN2;
    public:

    void init(int pwm, int BN1, int BN2);
    void go_forward(int power);
    void go_back   (int power);
    void hard_stop();
};
#endif
