int led = 12;
int ldr = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(ldr);
  int x = map(val,0, 4095, 0, 10);
  if (x <= 2)
  {
    digitalWrite(led, HIGH);
    Serial.println(x);
    Serial.println("Light is Low and LED is ON");
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println(x);
    Serial.println("Light is More and LED is OFF");
  }
  delay(500);

}
