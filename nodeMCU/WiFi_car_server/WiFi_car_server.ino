#include <Servo.h>
#include <ESP8266WiFi.h>

const char* ssid = "staniki_w_gore";
const char* password = "kiniacynia_458";
int kat;
int licznik =0;
int speed_ = 0;
String speed_s;
String kat_s;

#define LED D4
#define IN1 D1
#define IN2 D2
#define PWMa D3
#define SERVO_PIN D0
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(8802);
WiFiClient client;
Servo servomotor;
void setup() {
  Serial.begin(115200);
  delay(10);
 servomotor.attach(SERVO_PIN);
  // prepare GPIO2
  pinMode(LED, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  digitalWrite ( IN1, HIGH);
  digitalWrite (IN2 , HIGH );
  digitalWrite(LED, 0);
  analogWrite(PWMa, 255);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void wait_for_client ()
{
   digitalWrite(LED, 0);
  while (1)
  {
    if (licznik == 0){
   kat=random (36,106);
  servomotor.write(kat);   
Serial.println(kat);
    }
++licznik;
if (licznik == 90000)
{
  licznik =0;
} 
     // Check if a client has connected
    client = server.available();
  if (!client) {
    //Serial.print(".");
  }
  else
  {
    break;
  }
  }
  
} // end wait_for_clietn

void working (){
   digitalWrite(LED, 1);
  while (1){
     Serial.println("wait");
  while(!client.available()){
   // delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('#');
   
  client.flush();
 
  if (req =="DISCONNECT"){
    Serial.println("disconnect");
    break;
  }
  
   kat_s = req.substring(11,15);
  Serial.println("kat: "+ kat_s);
  kat = kat_s.toInt();
  kat = map(kat,-255,255,36,106);
  Serial.println(kat);
 servomotor.write(kat);
 speed_s=req.substring(26,31);
 speed_ = speed_s.toInt();
 Serial.println("speed");
 Serial.println(speed_);
 if (speed_ < 0 )
 {
  speed_ = speed_*-1;
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  analogWrite (PWMa, speed_);
  
 }
 else if ( speed_ == 0)
 {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  analogWrite (PWMa, 255);
  Serial.println("STOP");
 }

 else
 {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite (PWMa, speed_);
 }
 

  String s = "\nEND.\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("done");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
  }
} // end working
void loop() {
 
  wait_for_client();
  // Wait until the client sends some data
  working();
}

