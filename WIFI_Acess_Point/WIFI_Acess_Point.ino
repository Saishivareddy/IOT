#include "WiFi.h"
char ssid[] = "Shiva-ESP32";
char passwd[] = "qwertyuiop";

void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, passwd);
  Serial.print("Network Created with ssid :");
  Serial.println(ssid);
  Serial.println("Network is available to use");
}

void loop() {
  // put your main code here, to run repeatedly:
}
