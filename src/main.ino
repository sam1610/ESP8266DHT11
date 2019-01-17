#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`


#define DHTPIN D2
#define DHTTYPE DHT11

SSD1306  display(0x3c, D3, D5);
DHT dht(DHTPIN, DHTTYPE);
void setup(){
  // initialiser la vitesse de communication serie
    Serial.begin(9600);

     // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
      DHTstart();
    }
void loop(){
  displayTempHumid();
  display.display();
  delay(2000);
}

void displayTempHumid(){
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)){
    display.clear(); // clearing the display
    display.drawString(5,0, "Failed DHT");
    return;
  }
  display.clear();
  display.drawString(0, 0, "Humidity: " + String(h) + "%\t"); 
  display.drawString(0, 22, "Temp: " + String(t) + "C"); 
  display.drawString(0, 42, "Temp: " + String(f) + "F"); 
}




void DHTstart(){
  dht.begin();
}

