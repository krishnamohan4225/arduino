int pirPin = 34;    //the digital pin connected to the PIR sensor's output
int ledPin = 13;  // to display output
void setup() {
 Serial.begin(9600); // to initialize serial port of monitor.
 pinMode(pirPin, INPUT);
 pinMode(ledPin, OUTPUT);
 digitalWrite(pirPin, LOW); // initialization of input.

}
void loop() {
  if(digitalRead(pirPin) == HIGH) // checking for sensor motion
  {
       digitalWrite(ledPin, HIGH);
       Serial.println("motion detected");
  }
       else if(digitalRead(pirPin) == LOW){       
       digitalWrite(ledPin, LOW);
       Serial.println("motion  not detected");
       }
       delay(1000);
     }

