#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int triggerPin = 3;
const int echoPin = 2;
const int buttonPin = 4;

const int countOfMeasurements = 50;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

float measureDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  int pingTravelTime = pulseIn(echoPin, HIGH);
  delay(25);
  return (0.034 * pingTravelTime) / 2;
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Click to measure");

  int buttonVal = digitalRead(buttonPin);

  while (buttonVal == 1) {
    buttonVal = digitalRead(buttonPin);
  }

  while (buttonVal == 0) {
    buttonVal = digitalRead(buttonPin);
  }

  lcd.setCursor(0, 0);
  lcd.clear();
  lcd.print("Measuring...");

  float totalDistance = 0;

  for (int i = 0; i < countOfMeasurements; i++) {
    totalDistance += measureDistance();
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.print(totalDistance / countOfMeasurements);
  lcd.print("cm");
  delay(5000);
}