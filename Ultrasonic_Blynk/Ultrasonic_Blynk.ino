#define BLYNK_TEMPLATE_ID "TMPL-oiPMf-C"
#define BLYNK_DEVICE_NAME "Distance"
#define BLYNK_AUTH_TOKEN "uN-JFTpFP6qkNZjxPzPDTUSHGChOWFSK"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define trigpin 26
#define echopin 27
#define led 13
float distance = 0;
int duration = 0;

char ssid[] = "Shiva";
char pass[] = "shiva@1412";
char auth[] = BLYNK_AUTH_TOKEN;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delay(1);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = (duration*0.034)/2;
  Serial.print("Distance :");
  Serial.print(distance);
  Serial.println(" cm");
  Blynk.virtualWrite(V0, distance);
  Blynk.run();

  if(distance <= 15)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }

  delay(2000);
}
