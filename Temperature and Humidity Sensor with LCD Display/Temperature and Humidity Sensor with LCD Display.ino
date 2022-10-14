#include <LiquidCrystal.h>
#include <DHT.h>
#include <math.h>

const int sensePin = 2;
DHT dht = DHT(sensePin, DHT11);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  delay(500);
}

void loop() {
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();

  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(round(humidity));
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(round(temp));
  lcd.print((char)223);

  delay(1000);
  lcd.clear();
}
