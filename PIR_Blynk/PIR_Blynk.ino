#define BLYNK_TEMPLATE_ID "TMPLyjCcjR4N"
#define BLYNK_DEVICE_NAME "Motion Sensor"
#define BLYNK_AUTH_TOKEN "Dt5V38c251dj2N6Ug5i_DD-dudJUfC3K"
#define BLYNK_PRINT Serial

#define pir 13
#define led 12

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Shiva";
char pass[] = "shiva@1412";
char auth[] = BLYNK_AUTH_TOKEN;

void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  if(WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print("Connecting to ssid :");
    Serial.println(ssid);
  }
  int value = 0; 
  value = digitalRead(pir);
  Blynk.virtualWrite(V0, value);
  if(value == HIGH)
  {
    Serial.println("Motion Detected..");
    digitalWrite(led, HIGH);
    Blynk.virtualWrite(V1, HIGH);
    Serial.print("PIR Value is :");
    Serial.println(value);
//    delay(1000);
  }
  else 
  {
    Serial.println("No Motion Detected..");
    digitalWrite(led, LOW);
    Blynk.virtualWrite(V1, LOW);
    Serial.print("PIR Value is :");
    Serial.println(value);
//    delay(1000);
  }
  delay(2000);
  
}
