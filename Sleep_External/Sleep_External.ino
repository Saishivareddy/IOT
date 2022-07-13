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

esp_sleep_enable_ext0_wakeup(GPIO_NUM_36,1);
Serial.println("Going to sleep");
delay(500);
esp_light_sleep_start();
}
