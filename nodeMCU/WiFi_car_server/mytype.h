#ifndef MYTYPE_H
#define MYTYPE_H
#include <Arduino.h>
#include "Engine.h"
#include "Light.h"

#define LED         D4
#define FRONT_LED   D5
#define BACK_LED    D6
#define IN1         D1      // GPIO 5
#define IN2         D2      // GPIO 4
#define PWMa        D3      // GPIO 0
#define SERVO_PIN   D7      // GPIO 13

#define STOP_LED_TIMER  60
struct Wifi_data {
  String ssid;
  String password;
};
#endif
