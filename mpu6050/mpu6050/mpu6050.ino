
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Arduino.h>
#include "serverP.h"

#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

const char* ssid = "ESP8266-Access-Point";
const char* password = "123456789";

AsyncWebServer server(80);

MPU6050 ShoulderMpu6050(Wire,GPIO05,GPIO04);

long timer = 0;

String readXAngle() {
  return String(ShoulderMpu6050.getAngleX());
  //return String(1.8 * bme.readTemperature() + 32);
}

String readYAngle() {
  return String(ShoulderMpu6050.getAngleY());
}

String readZAngle() {
  return String(ShoulderMpu6050.getGyroAngleZ());
}

void setup() {
  //Serial.begin(9600);
  Serial.begin(115200);

  WiFi.softAP(ssid,password);
  IPAddress IP = WiFi.softAPIP();
  
  Wire.begin();
  ShoulderMpu6050.begin();
  ShoulderMpu6050.calcGyroOffsets(true);

  server.on("/XAngle", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send_P(200, "text/plain", readXAngle().c_str());
  });
  server.on("/YAngle", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send_P(200, "text/plain", readYAngle().c_str());
  });
  server.on("/ZAngle", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    request->send_P(200, "text/plain", readZAngle().c_str());
  });

  server.begin();
}



void loop() {
  ShoulderMpu6050.update();

  //if(millis() - timer > 1000){
    
    //Serial.println("=======================================================");
    //Serial.print("temp : ");Serial.println(ShoulderMpu6050.getTemp());
    //Serial.print("accX : ");Serial.print(ShoulderMpu6050.getAccX());
    //Serial.print("\taccY : ");Serial.print(ShoulderMpu6050.getAccY());
    //Serial.print("\taccZ : ");Serial.println(ShoulderMpu6050.getAccZ());
  
    //Serial.print("gyroX : ");Serial.print(ShoulderMpu6050.getGyroX());
    //Serial.print("\tgyroY : ");Serial.print(ShoulderMpu6050.getGyroY());
    //Serial.print("\tgyroZ : ");Serial.println(ShoulderMpu6050.getGyroZ());
  
    //Serial.print("accAngleX : ");Serial.print(ShoulderMpu6050.getAccAngleX());
    //Serial.print("\taccAngleY : ");Serial.println(ShoulderMpu6050.getAccAngleY());
  
    //Serial.print("gyroAngleX : ");Serial.print(ShoulderMpu6050.getGyroAngleX());
    //Serial.print("\tgyroAngleY : ");Serial.print(ShoulderMpu6050.getGyroAngleY());
    //Serial.print("\tgyroAngleZ : ");Serial.println(ShoulderMpu6050.getGyroAngleZ());
    
    //Serial.print("angleX : ");Serial.print(ShoulderMpu6050.getAngleX());
    //Serial.print("\tangleY : ");Serial.print(ShoulderMpu6050.getAngleY());
    //Serial.print("\tangleZ : ");Serial.println(ShoulderMpu6050.getAngleZ());
    //Serial.println("=======================================================\n");
    //timer = millis();
    //ShoulderMpu6050.
    
    
  //}
}
