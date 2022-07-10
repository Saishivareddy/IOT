#include <ThingSpeak.h>
#include <WiFi.h>

#define trigpin 26
#define echopin 27
#define led 13
float distance = 0;
int duration = 0;

WiFiClient client;
char ssid[] = "Shiva";
char pass[] = "shiva@1412";

long channel = 1795117;
int channelfield = 1;
char auth[] = "JAZ57NN98P3CEZ1L";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(led, OUTPUT);
  Serial.print("Trying to connect to ssid :");
  Serial.println(ssid);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(WiFi.status() != WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(500);
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Connected");
  }
  }
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
    
    if(distance <= 15)
    {
      digitalWrite(led, HIGH);
    }
    else
    {
      digitalWrite(led, LOW);
    }
  ThingSpeak.writeField(channel, channelfield, distance, auth);
  delay(2000);
}
