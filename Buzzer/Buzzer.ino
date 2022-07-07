int Buzzer = 12;  // Buzzer connected to Pin 12
void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Buzzer, HIGH);
  Serial.println("Buzzer ON");
  delay(1000);
  digitalWrite(Buzzer, LOW);
  Serial.println("Buzzer OFF");
  delay(1000);
}
