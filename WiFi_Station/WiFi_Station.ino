#include "WiFi.h"

char* ssid ="Shiva";
char* passwd ="shiva@1412";

void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_STA);  // Station Mode of WIFI
  Serial.begin(9600);
  WiFi.disconnect();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.print("Connected to ssid :");
    Serial.println(ssid);
  }
  else
  {
    WiFi.begin(ssid, passwd);
    Serial.print("Trying to connect to ssid :");
    Serial.println(ssid);
    delay(2000);
  }
  delay(5000);
}
