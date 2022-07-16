#define BLYNK_TEMPLATE_ID "TMPLUvr2_RX6"
#define BLYNK_DEVICE_NAME "Temperature and Humidity Using DHT11"
#define BLYNK_AUTH_TOKEN "msJ8PUKT34KzOQ0vOm0p_VNF_3wTHIFr"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#define dhtpin 13

char auth[] = "msJ8PUKT34KzOQ0vOm0p_VNF_3wTHIFr";
char ssid[] = "Shiva";
char passwd[] = "shiva@1412";

DHT dht(dhtpin, DHT11);
int state = LOW;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, passwd);
  dht.begin();
}

BLYNK_WRITE(V2)
{
  state = param.asInt();
}
void loop()
{
  Blynk.run();
  if ( state == HIGH)
  {
    float temp = dht.readTemperature();
    float hum  = dht.readHumidity();
    if (isnan(temp) || isnan(hum))
    {
      Serial.println("Failed to read from DHT11");
      delay(1000);
    }
    else
    {
      Serial.print("Temperature :");
      Serial.println(temp);
      Serial.print("Humidity    :");
      Serial.println(hum);
      Blynk.virtualWrite(V0, temp);
      Blynk.virtualWrite(V1, hum);
      delay(5000);
    }
  }
}
