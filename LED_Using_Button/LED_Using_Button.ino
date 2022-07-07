int led =12;
int button = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button) == HIGH)
  {
    digitalWrite(led, HIGH);
    Serial.println("LED is ON");
    delay(1000);
  }
  else
  {
    digitalWrite(led, LOW);
    Serial.println("LED is OFF");
  }
}
