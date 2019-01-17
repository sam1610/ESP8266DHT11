#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#define DHTPIN D2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup(){
    Serial.begin(9600);
    DHTstart();
    }
void loop(){
  Serial.print("Temperature = "); 
  Serial.print(ReadT());
  Serial.println(" C");
  Serial.print("Humidity = "); 
  Serial.print(ReadH());
  Serial.println(" %");
  delay(1000);
}




void DHTstart(){
  dht.begin();
}

float ReadT(){
  float t = dht.readTemperature();
  return t;
}

float ReadH(){
  float h = dht.readHumidity();
  return h;
}