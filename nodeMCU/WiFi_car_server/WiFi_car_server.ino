#include <Servo.h>
#include <ESP8266WiFi.h>

#include "mytype.h"
#include "functions.h"
#include "light.h"
#include "engine.h"

int kat;
int licznik = 0;
int speed_ = 0;
String speed_s;
String kat_s;
constexpr int port = 8833;


Engine mainMotor;
Light lightFront(FRONT_LED);
Light lightBack  (BACK_LED);

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(port);
WiFiClient client;
Servo servomotor;


void setup() {
  Serial.begin(74880);
  delay(10);
  servomotor.attach(SERVO_PIN);
  servomotor.write(60);
 
 
  digitalWrite(LED, 0);
 //analogWriteFreq(20);
  // Connect to WiFi network

  setupWiFi();
  OTA_update_setup();
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  mainMotor.init(PWMa, IN1, IN2);
   lightBack.turnOFF();
   lightFront.turnOFF();
}

void wait_for_client() {
  digitalWrite(LED, 0);
  while (1) {
    if (licznik == 0) {
      //kat = random(36, 106);
      //servomotor.write(kat);

      //Serial.println(kat);

      //Serial.println(analogRead(A0));
      OTA_handle();
    }
    ++licznik;
    if (licznik == 90000) {
      licznik = 0;
    }
    // Check if a client has connected
    client = server.available();
    if (!client) {
      // Serial.print(".");
    } else {
      break;
    }
  }

}  // end wait_for_clietn

void working() {
  digitalWrite(LED, 1);
  while (1) {
    Serial.println("wait");
    while (!client.available()) {
      // delay(1);
    }

    // Read the first line of the request
    String req = client.readStringUntil('#');

    client.flush();
    Serial.println("odebralem: " + req);
    if (req == "DISCONNECT") {
      Serial.println("disconnect");
      break;
    }

    if (req == "SLEEP") {
      ESP.deepSleep(10000000);
    }

    kat_s = req.substring(10, 14);
    Serial.print("kat str: ");
    Serial.println(kat_s);
    kat = kat_s.toInt();
    kat = map(kat, -100, 100, 36, 106);
    Serial.print("kat int: ");

    Serial.println(kat);
    servomotor.write(kat);
    speed_s = req.substring(5, 9);
    Serial.print("speed str: ");
    Serial.println(speed_s);
    speed_ = speed_s.toInt();
    Serial.print("speed_int: ");
    Serial.println(speed_);
    if (speed_ < 0) {
      speed_ = speed_ * -1;
       
      mainMotor.go_forward(  map(speed_, 0, 100, 0, 1020));
      //req = "forward";

    } else if (speed_ == 0) {
      mainMotor.hard_stop();
      //req = "stop";
    }

    else {
      mainMotor.go_back( map(speed_, 0, 100, 0, 1020));
      //req="back";
    }
/// light ///////////////

if (1 == req.substring(20, 21).toInt()){
  
   lightFront.turnON_max();
}
else{
  lightFront.turnOFF();
}
if (1 == req.substring(22, 23).toInt()){
  lightBack.turnON_half();
}
else{
  lightBack.turnOFF();
}

    String s = " 15-16"+req.substring(20, 21)+" "+req.substring(22, 23) ;

    // Send the response to the client
    client.print(s);
    delay(1);
    Serial.println("done :)");

    // The client will actually be disconnected
    // when the function returns and 'client' object is detroyed
  }
}  // end working
void loop() {
  wait_for_client();
  // Wait until the client sends some data
  working();
  mainMotor.hard_stop();
}

