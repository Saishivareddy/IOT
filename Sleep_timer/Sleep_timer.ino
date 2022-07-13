#include <DHT.h>

#define dhtpin 13
float temp = NULL;
float hum = NULL;

DHT dht(dhtpin, DHT11);

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  hum  = dht.readHumidity();
  temp = dht.readTemperature();
  if (isnan(hum) || isnan(temp))
  {
    Serial.println("Failed to read from DHT11 Sensor");
//    delay(2000);
  }
  else
  {
    Serial.print("Temperature :");
    Serial.println(temp);
    Serial.print("Humidity    :");
    Serial.println(hum);
//    delay(2000);
  }
  Serial.println("Going to Sleep Mode");
  delay(500);
  esp_sleep_enable_timer_wakeup(20 *1000000);
  esp_deep_sleep_start();
  Serial.println("Controller wakeup from Sleep Mode");
}
