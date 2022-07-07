int led = 12;
int ldr = 13; 
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
pinMode(ldr, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(ldr);

  if(val <= 511)
  {
    digitalWrite(led, HIGH);
    Serial.println(val);
    Serial.println("Light is Low and LED is ON");
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println(val);
    Serial.println("Light is More and LED is OFF");
  }
  delay(500);

}
