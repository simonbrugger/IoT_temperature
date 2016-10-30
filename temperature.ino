#include "Adafruit_DHT.h"


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

  Particle.publish("Temperatur", String(temperature), PRIVATE);
  Particle.publish("Luftfeuchtigkeit", String(humidity), PRIVATE);

  delay(5000);
}
