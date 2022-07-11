#define pir 13
#define led 12

#include <ThingSpeak.h>
#include <WiFi.h>

char ssid[] = "Shiva";
char pass[] = "shiva@1412";
WiFiClient client;
long channel = 1795621;
int field = 1;
char auth[] = "UWPNVHXL4Z1MUD28";

void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, pass);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
    delay(5000);
  }
  int value = 0; 
  value = digitalRead(pir);
  ThingSpeak.writeField(channel, field, value, auth);
  if(value == HIGH)
  {
    Serial.println("Motion Detected..");
    digitalWrite(led, HIGH);
    Serial.print("PIR Value is :");
    Serial.println(value);
  }
  else 
  {
    Serial.println("No Motion Detected..");
    digitalWrite(led, LOW);
    Serial.print("PIR Value is :");
    Serial.println(value);
  }
  delay(1000);
}
