#include "Adafruit_DHT/Adafruit_DHT.h"

// DHT parameters
#define DHTPIN 5
#define DHTTYPE DHT22

int temperature;
int humidity;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
   dht.begin();
}

void loop() {
   temperature = dht.getTempCelcius();
   humidity = dht.getHumidity();

   Particle.publish("temperature", String(temperature), PRIVATE);
   Particle.publish("humidity", String(humidity), PRIVATE);

   delay(5000); //5 seconds delay
}
