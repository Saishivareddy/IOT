int led = 13;  // LED connected to Pin 13
void setup() {
  pinMode(led,OUTPUT);  
  Serial.begin(9600);
}

void loop() {
 
  digitalWrite(led, HIGH);
  Serial.println("LED is ON");
  delay(500);
  digitalWrite(led, LOW);
  Serial.println("LED is OFF");
  delay(500);
}
