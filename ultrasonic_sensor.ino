int trigPin = 12; // assigning pin to trigger output of sensor
int echoPin = 11; // assigning pin to echo input of sensor
long cm; // initialization of distance
void setup() {
  Serial.begin(9600); // to initiate serial monitor port
   Serial.println("This is ultrasonic sensor :");
  delay(100);   
}
void loop() {
  long duration, inches; // defining variables
  pinMode(trigPin, OUTPUT);// trigger output will remain low for 2us.
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // trigger output will remain high for 10us.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = (duration/ 74 / 2);// converts duration into inches.
  cm = (duration/ 29 / 2);
  Serial.println("distance is : ");
  Serial.println(cm);
  Serial.println("cm");
  delay(1000);
}

