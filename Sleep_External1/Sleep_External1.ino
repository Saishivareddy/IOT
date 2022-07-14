#define led 12

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  pinMode(led, OUTPUT);
  Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);

  esp_sleep_enable_ext1_wakeup(0x6000, ESP_EXT1_WAKEUP_ANY_HIGH);  // Pin Numbers 13 and 14 = 0x6000
  Serial.println("Going to sleep");
  delay(500);
  esp_deep_sleep_start();
}
