#include "ThingSpeak.h"
#include "WiFi.h"
#include <DHT.h>  // Include library for dht
  
//----------- Enter you Wi-Fi Details---------//
char ssid[] = "Shiva"; //SSID
char pass[] = "shiva@1412"; // Password
//-------------------------------------------//


#define DHTPIN 13          //pin where the dht11 is connected

float humidity = 0.0;
float temp = 0.0;
DHT dht(DHTPIN, DHT11);
WiFiClient  client;

unsigned long myChannelField =  1792365; // Channel ID
const int ChannelField1 = 1; // Which channel to write data
const int ChannelField2 = 2;
const char * myWriteAPIKey = "PA5O3BTOZKRINXN9"; // Your write API Key


void setup()
{
  Serial.begin(115200);
  dht.begin();
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop()
{
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
  
   humidity = dht.readHumidity();    // read humidity for sensor
   temp = dht.readTemperature();     // read temperature for sensor

//    if (isnan(humidity) || isnan(temp)) 
//      {
//        Serial.println("Failed to read from DHT sensor!");
//        delay(5000);
//        return;
//      }
      
  /* printing the results on console*/
      Serial.print("Temperature: ");
      Serial.print(temp);
      Serial.print(" ^0C, Humidity: ");
      Serial.print(humidity);
      Serial.println("%");
        
      delay(10000);
  ThingSpeak.writeField(myChannelField, ChannelField1, temp, myWriteAPIKey);
  ThingSpeak.writeField(myChannelField, ChannelField2, humidity, myWriteAPIKey);
  
  delay(1000);
}
