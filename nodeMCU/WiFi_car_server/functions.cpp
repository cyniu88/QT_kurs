#include "functions.h"

void setupWiFi(){
  pinMode(LED,OUTPUT);
  Serial.println();
  Serial.println();
  Light lightFront(FRONT_LED);
  Light lightBack  (BACK_LED);
  bool ledState = true;
  const int networkNumber = 3;
  Wifi_data data[networkNumber];
  data[0].ssid      = "cyniu";
  data[0].password  = "123456789";
  data[1].ssid      = "staniki_w_gore";
  data[1].password  = "kiniacynia_458"; 
  data[2].ssid      =  "EPOL_kd@012" ;
  data[2].password  = "epolepol";
  WiFi.mode(WIFI_STA);

  for (int i = 0 ; i < networkNumber; ++i){
    Serial.print("\nconnecting to: ");
    Serial.println(data[i].ssid);
     WiFi.begin(data[i].ssid.c_str(), data[i].password.c_str());
     int counter = 0;
     while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
          ledState = !ledState;
          digitalWrite(LED, ledState);
          if (ledState)
          {
            lightFront.turnON();
            lightBack.turnOFF();
          }
          else{
            lightBack.turnON();
            lightFront.turnOFF();
          }
          if(++counter>20){
           break;
          }
       }
      if (WiFi.status() == WL_CONNECTED){
        lightFront.turnOFF();
        lightBack.turnOFF();
        return;
      }
      
    }
    Serial.println("not connected so restart :(");
    ESP.restart();
}

void OTA_update_setup(){
  ArduinoOTA.setHostname("esp8266-wifi-car");
  ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
   // Print the IP address
  Serial.println(WiFi.localIP());

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void OTA_handle(){
  ArduinoOTA.handle();
}

