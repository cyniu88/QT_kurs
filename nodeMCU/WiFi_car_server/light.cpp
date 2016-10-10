#include "light.h"


Light::Light(int _ledPIN)
    : ledPIN(_ledPIN)
{
    pinMode(ledPIN, OUTPUT);
    digitalWrite(ledPIN, LOW);
}

void Light::turnON_half()
{
    analogWrite(ledPIN, 512);
}

void Light::turnON_max()
{
    digitalWrite(ledPIN, HIGH);
}
void Light::turnOFF()
{
    digitalWrite(ledPIN, LOW);
}

