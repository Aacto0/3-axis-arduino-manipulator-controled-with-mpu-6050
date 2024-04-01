#include <Bridge.h>
#include <HttpClient.h>

const char* serverNameXAngle = "http://192.168.4.1/XAngle";
const char* serverNameYAngle = "http://192.168.4.1/YAngle";
const char* serverNameZAngle = "http://192.168.4.1/ZAngle";

void setup() {
   Serial.begin(9600);
}

String httpGETRequest(const char* serverName) {

  HttpClient client;

  int httpResponseCode = client.get(serverName);

  //String payload = "--"; 

  // if (httpResponseCode>0)
  // {
  //   String payload = String(httpResponseCode);
  // }
  String payload = String(client.read());
  return payload;
}

void loop() {

  HttpClient client;

  Serial.print(httpGETRequest("http://192.168.4.1/XAngle")+"\n");
  //  while (client.available()) {

  //    char c = client.read();

  //    //Serial.print(c+"\n");
  //    //Serial.print("a");
  //    //delay(1000);

  //  }

  Serial.flush();

  delay(500);
}