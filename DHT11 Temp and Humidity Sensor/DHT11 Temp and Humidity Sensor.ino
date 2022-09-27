#include <DHT.h>

int sensePin = 2;
DHT dht = DHT(sensePin, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(500);
}

void loop() {
  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(", Temp: ");
  Serial.print(tempC);
  Serial.print("C, ");
  Serial.print(tempF);
  Serial.println("F");
  delay(500);
}
