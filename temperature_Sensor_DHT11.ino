#include <dht.h>
dht DHT;  
#define DHT11_PIN 31 //   sensor pin to arduino pin no 32  

void setup() {
Serial.begin(9600);

Serial.println("  This is Humidity and temperature Detector"); }

void loop() { // READ DATA

int chk = DHT.read11(DHT11_PIN);

Serial.println(" Humidity " );
Serial.println(DHT.humidity  ,1);
delay(100);
Serial.println(" Temparature ");
Serial.println(DHT.temperature  , 1);
delay(500);
}

