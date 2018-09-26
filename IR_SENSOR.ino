int isObstaclePin = 30;
int isObstacle = HIGH;

void setup() 
 { 
  pinMode(10, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(isObstaclePin , INPUT);
  Serial.begin(9600);  
  
}

void loop() {
  digitalWrite(34,HIGH);
 isObstacle = digitalRead(isObstaclePin);
  if (isObstacle == HIGH)
  {
    Serial.println("OPEN");
    delay(100);
   digitalWrite(10, HIGH);
  }
  else
  {
    Serial.println("CLOSE");
    delay(100);
    digitalWrite(10, LOW);
  }
      delay(200);
}

