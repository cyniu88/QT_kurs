#include "light.h"


Light::Light(int _ledPIN)
    : ledPIN(_ledPIN)
{
    pinMode(ledPIN, OUTPUT);
    digitalWrite(ledPIN, LOW);
}

void Light::turnON_half()
{
    analogWrite(ledPIN, 112);
}

void Light::turnON_max()
{
    analogWrite(ledPIN, 1023);
}
void Light::turnOFF()
{
    analogWrite(ledPIN, 0);
}

