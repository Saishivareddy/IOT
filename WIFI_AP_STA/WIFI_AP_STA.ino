#include "WiFi.h"
char ssid[] = "Shiva";
char passwd[] = "shiva@1412";

char ssid1[] = "Shiva-ESP32";
char passwd1[] = "qwertyuiop";

void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid1, passwd1);
  Serial.begin(9600);
  Serial.print("Network Created with ssid :");
  Serial.println(ssid);
  Serial.println("Network is available to use");
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
    Serial.println("Trying to connect");
  }
  delay(5000);
}
