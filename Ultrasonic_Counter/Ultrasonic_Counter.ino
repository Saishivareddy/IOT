#define trig 26
#define echo 27
#define trig_exit 22
#define echo_exit 23
#define led_entry 14
#define led_exit 21
int count = 0;
float distance = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(trig_exit, OUTPUT);
  pinMode(echo,INPUT);
  pinMode(echo_exit, INPUT);
  pinMode(led_entry, OUTPUT);
  pinMode(led_exit, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delay(5);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  float distance = (duration* 0.034)/2;
  if(distance == 0)
  {
    distance = 100;
  }
  Serial.print("Entry Distance :");
  Serial.println(distance);
  delay(1000);

  digitalWrite(trig_exit, LOW);
  delay(2);
  digitalWrite(trig_exit, HIGH);
  delay(10);
  digitalWrite(trig_exit, LOW);
  int duration_exit = pulseIn(echo_exit, HIGH);
  float distance_exit = (duration_exit* 0.034)/2;
  Serial.print("Exit Distance :");
  Serial.println(distance_exit);
//  delay(3000);
  
  if(distance < 15)
  {
    count = count+1;
    digitalWrite(led_entry, HIGH);
    delay(500);
    digitalWrite(led_entry, LOW);
    Serial.println("Person Entered into Room");
  }
  else if(distance_exit < 15)
  {
    count = count-1;
    digitalWrite(led_exit, HIGH);
    delay(500);
    digitalWrite(led_exit, LOW);
    Serial.println("Person Exited from Room");
  }
//  
//  digitalWrite(led_exit, LOW);
  if(count < 0)
  {
    count = 0;
  }
  Serial.print("Number of persons in room :");
  Serial.println(count);
//  delay(1000);
}
