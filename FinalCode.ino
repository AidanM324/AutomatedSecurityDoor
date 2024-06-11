
// handleRoot() builds up the webpage by adding as a C++ String:
// homePagePart1 + getTemp() +homePagePart2 
// It then serves the webpage with the command:  
// server.send(200, "text/html", message);


#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "DHT11.h"
#include "Index.h"
#include "Admin.h"
#include <Adafruit_PN532.h>
#include <Servo.h>
#include "rgb_lcd.h"
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 14

Adafruit_PN532 nfc(SDA, SCL);
rgb_lcd lcd;
Servo servo1;
WebServer server(80);

const char* ssid = "Aidan";
const char* password = "Aidan123";
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
static const int SERVO_PIN = 13;
const int TRIG_PIN = 5;  //trigger
const int ECHO_PIN = 18;  //echo
long duration; // used to measure time transition until echo returns
float cms;



String getTemp(){
  DHT.read (DHT11_PIN);
  String temp = String(DHT.temperature);
  return temp;
}

String getHumidity(){
  DHT.read (DHT11_PIN);
  String temp = String(DHT.humidity);
  return temp;
}

void handleMain(){
String message = MainPagePart1;
server.send(200, "text/html", message);
}

void handleAdmin(){
String message = MainAdminPart1;
server.send(200, "text/html", message);
}

void handleRoot() {
  String message = homePagePart1 + getTemp() + homePagePart2;
  server.send(200, "text/html", message);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {

  Serial.begin(115200);
  servo1.attach(SERVO_PIN);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);

  nfc.begin();
  nfc.SAMConfig();

 pinMode(TRIG_PIN, OUTPUT);
 pinMode(ECHO_PIN, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleMain);
  server.on("/admin", handleAdmin);
  server.on("/DHT11", handleRoot);
  
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}



void rfidReader() {
  Serial.println("Waiting for an RFID card...");

  uint8_t success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };
  uint8_t uidLength;

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);

  if (success) {
    Serial.println("Found an RFID card!");

    // let's assume any card is valid in this example
    Serial.println("Card is valid!");

    delay(1000);

    lcd.print("Welcome User.");

    delay(3000);

    lcd.clear();

    servoLCD();
  }

  else {

    lcd.clear();

    lcd.print("!ACCESS DENIED!");
    delay(2000);
    lcd.clear();
  }
  delay(1000);
}

void servoLCD() {
  lcd.print("!Access Granted!");
  delay(2000);

  lcd.clear();

  lcd.print("!DOOR OPENING!");

  // servo opening door

  for (int posDegrees = 0; posDegrees <= 90; posDegrees++) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(50);
  }
  delay(5000);

  lcd.clear();

  delay(5000);

  lcd.print("!DOOR CLOSING!");

  // servo closing door

  for (int posDegrees = 90; posDegrees >= 0; posDegrees--) {
    servo1.write(posDegrees);
    Serial.println(posDegrees);
    delay(50);
  }
  delay(5000);

  lcd.clear();
}

void loop(void) {
  server.handleClient();
  delay(2);//allow the cpu to switch to other tasks

// The sensor is triggered by a HIGH pulse of ten or more microseconds.
 // Give a short LOW pulse beforehand to give a clean HIGH pulse:

 digitalWrite(TRIG_PIN, LOW);
 delayMicroseconds(5);
 digitalWrite(TRIG_PIN, HIGH);
 delayMicroseconds(10);
 digitalWrite(TRIG_PIN, LOW);

// read the signal from the sensor: a HIGH pulse 
// whose duration is the time (in microseconds) from the sending of the ping
// to the reception of its echo off an object.
duration = pulseIn(ECHO_PIN, HIGH);

// convert the time into a distance
cms = (duration/2) / 29.1;  // Divide by 29.1  or multiply by 0.0343

Serial.print(cms);
Serial.print("cm");
Serial.println();


if( cms <= 100)
{

Serial.print("Object Detected! ");

rfidReader();

}

delay(250);
  
}
