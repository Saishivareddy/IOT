#define pir 13
#define led 12

void setup() {
  // put your setup code here, to run once:
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int value = 0; 
  value = digitalRead(pir);

  if(value == HIGH)
  {
    Serial.println("Motion Detected..");
    digitalWrite(led, HIGH);
    Serial.print("PIR Value is :");
    Serial.println(value);
//    delay(1000);
  }
  else 
  {
    Serial.println("No Motion Detected..");
    digitalWrite(led, LOW);
    Serial.print("PIR Value is :");
    Serial.println(value);
//    delay(1000);
  }
  delay(2000);
}
