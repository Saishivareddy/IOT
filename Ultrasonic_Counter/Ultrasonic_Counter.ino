#define BLYNK_TEMPLATE_ID "TMPL-oiPMf-C"
#define BLYNK_DEVICE_NAME "Distance"
#define BLYNK_AUTH_TOKEN "EXh0K3A_6Lrxv38ad9jvDLQPlMAKXBk7"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char ssid[] = "Shiva";
char pass[] = "shiva@1412";
char auth[] = BLYNK_AUTH_TOKEN;

int Entry_Trig = 12;
int Entry_Echo = 14;
int Exit_Trig = 26;
int Exit_Echo = 27;
int Entry_led = 13;
int Exit_led = 23;
int count = 0;

float Entry_duration = 0;
float Entry_distance = 0;
float Exit_duration = 0;
float Exit_distance = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(Entry_Trig, OUTPUT);
  pinMode(Exit_Trig, OUTPUT);
  pinMode(Entry_Echo, INPUT);
  pinMode(Exit_Echo, INPUT);
  pinMode(Entry_led, OUTPUT);
  pinMode(Exit_led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  digitalWrite(Entry_Trig, HIGH);
  digitalWrite(Exit_Trig, HIGH);
  delay(10);
  digitalWrite(Entry_Trig, LOW);
  digitalWrite(Exit_Trig, LOW);
 
  Entry_duration = pulseIn(Entry_Echo, HIGH);
  Exit_duration = pulseIn(Exit_Echo, HIGH);
  Entry_distance = (Entry_duration*0.034)/2;
  Exit_distance = (Exit_duration*0.034)/2;
  Blynk.virtualWrite(V0, Entry_distance);
  Blynk.virtualWrite(V1, Exit_distance);
  if(Entry_distance < 30)
  {
    count++;
    digitalWrite(Entry_led, HIGH);
    Serial.println("Person Entered");
    Blynk.virtualWrite(V2, "Person Entered");
  }
  else if(Exit_distance <30)
  {
    count--;
    digitalWrite(Exit_led, HIGH);
    Serial.println("Person Exited");
    Blynk.virtualWrite(V2, "Person Exited");
  }
  else
  {
    digitalWrite(Entry_led, LOW);
    digitalWrite(Exit_led, LOW);
  }
  Serial.print("Number of Persons in Room :");
  Serial.println(count);
  Blynk.virtualWrite(V3,count);
}
