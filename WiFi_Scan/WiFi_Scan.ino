#include "WiFi.h"

void setup() {
  // put your setup code here, to run once:
  WiFi.mode(WIFI_STA);  // Station Mode of WIFI
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int n = WiFi.scanNetworks();
  for(int i =0 ; i<=n; i++)
  {
    Serial.print(i+1);
    Serial.print("-->");
    Serial.print(WiFi.SSID(i));
    Serial.print("---");
    Serial.println(WiFi.encryptionType(i));
  }
  delay(5000);
}
