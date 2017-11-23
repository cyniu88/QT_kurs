#ifndef  PCF8574_H
#define  PCF8574_H
#include <Arduino.h>
#include <Wire.h>
class  PCF8574 {
    byte m_addr = 0x20;
    byte m_data = 0x00;
  public:
    PCF8574();
    PCF8574(byte addr);
    void digitalWrite(byte pin, byte state);
    void clearAll();
};
#endif
