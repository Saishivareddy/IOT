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

void dhtfun(){
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
  }
  void loop() {
  touchAttachInterrupt(T3, dhtfun, 30);  // Processor will goto sleep; Wakeup and continue with dhtfun() 
  esp_sleep_enable_touchpad_wakeup();
  esp_light_sleep_start();
  Serial.println("Controller wakeup from Sleep Mode");
}
