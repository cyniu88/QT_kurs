#include "functions.h"

void setupWiFi(){
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
          if(++counter>20){
           break;
          }
       }
      if (WiFi.status() == WL_CONNECTED){
        return;
      }
      
    }
    Serial.println("not connected so restart :(");
    ESP.restart();
}
