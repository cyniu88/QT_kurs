#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "mytype.h"

void setupWiFi();
void OTA_update_setup();
void OTA_handle();

#endif
