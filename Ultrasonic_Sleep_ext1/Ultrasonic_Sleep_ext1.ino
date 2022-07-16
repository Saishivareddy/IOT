#define trigpin 27
//#define echopin 27
#define led 13
float distance = 0;
int duration = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigpin, OUTPUT);
//  pinMode(echopin, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delay(1);
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(26, HIGH);
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
  esp_sleep_enable_ext1_wakeup(0x4000000, ESP_EXT1_WAKEUP_ANY_HIGH);
  esp_deep_sleep_start();
//  delay(2000);
}