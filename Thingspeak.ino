String ssid = "Krish";
String password = "krishna1";
String APIKEY="4GXA09O9Z3FSV841";     // Replace with your Thingspeak apikey
String strdistance = "";
String server = "184.106.153.149"; //api.thingspeak.com
int trigPin = 11;
int echoPin = 12;
String Status = "false";
String parkingStatus = "false";
long currentValue = 0.00;
long previousValue = 0.00;

void setup() {
  Serial1.begin(115200);
  Serial.begin(115200);
  delay(100);
  Serial.println("Started...");
  Serial1.println("AT+CWMODE=1\r");
  delay(1000);
  connectWifi();
}

void connectWifi() {
  String cmd = "AT+CWJAP=\"" + ssid + "\",\"" + password + "\"";
  Serial.println(cmd);
  Serial1.println(cmd);
  delay(4000);

  if (Serial1.find("OK")) {
    Serial.println("Connected!");
  }
  else {
    connectWifi();
    Serial.println("Cannot connect to wifi");
  }
}

void loop () {

  long duration, inches;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = (duration/ 74 / 2);
  currentValue = (duration/ 29 / 2);
  Serial.println(currentValue);
  httppost();
  if(currentValue <= 17 && currentValue != 0){
    Serial.println("Parked");
    Status = "true";
   }
   else{
   Serial.println("not parked");
   Status = "false";
  }
 
  if(Status != parkingStatus){
         
       Serial.println("hello");
    }
 
 parkingStatus = Status;
 delay(6000);
}

void httppost() {

  Serial1.println("AT+CIPSTART=\"TCP\",\"" + server + "\",80");//start a TCP connection.
  delay(500);
  if ( Serial1.find("OK")) {
    Serial.println("TCP connection ready");
  } 
  else{
   Serial.println("TCP connection not ready");
  }
    String getStr = "GET /update?api_key=";
    getStr += APIKEY;
    getStr +="&field1=";
    getStr += String(currentValue);
    getStr += "\r\n\r\n";  
    String postRequest = "POST /update/ HTTP/1.1\n""Host: "+ server +"\n" "Connection: close\n""X-THINGSPEAKAPIKEY:"+APIKEY+"\n""Content-Type: application/x-www-form-urlencoded\n""Content-Length:"+getStr.length()+"\n\n";
     postRequest+=getStr;             
  String sendCmd = "AT+CIPSEND=";//determine the number of caracters to be sent.

  Serial1.print(sendCmd);
  Serial1.println(postRequest.length() );

  delay(500);

  if (Serial1.find(">")) {
    Serial.println("Sending.."); Serial1.print(postRequest);

    if ( Serial1.find("SEND OK")) {
      Serial.println("Packet sent");
      while (Serial1.available()) {
        String tmpRSerial1 = Serial1.readString();
        Serial.println(tmpRSerial1);
      }

      // close the connection
      Serial1.println("AT+CIPCLOSE");
    }
  }
}

/*long microsecondsToInches(long microseconds){
  
  return microseconds / 74 / 2;

}
 
long microsecondsToCentimeters(long microseconds){
  
  return microseconds / 29 / 2;
  
}*/

