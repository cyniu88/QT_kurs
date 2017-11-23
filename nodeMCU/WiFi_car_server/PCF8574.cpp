#include "PCF8574.h"

PCF8574::PCF8574() {
  Wire.begin(D2, D1);
  clearAll();
}
PCF8574::PCF8574(byte addr): m_addr(addr)
{
  Wire.begin(D2, D1);
  clearAll();
}

void PCF8574::clearAll() {
  Wire.beginTransmission(m_addr);
  Wire.write(m_data);
  Wire.endTransmission();
}
void PCF8574::digitalWrite(byte pin, byte state) {
  if (state == HIGH)
    m_data |= 1 << pin;
  else
    m_data &= ~(1 << pin);

  Wire.beginTransmission(m_addr);
  Wire.write(m_data);
  Wire.endTransmission();
}

