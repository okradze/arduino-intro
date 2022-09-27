#include <LiquidCrystal.h>
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

float askForCircleRadius() {
  lcd.setCursor(0, 0);
  lcd.print("Enter circle");
  lcd.setCursor(0, 1);
  lcd.print("radius: ");

  while(Serial.available() == 0) {}
  float radius = Serial.parseFloat();
  lcd.clear();
  return radius;
}

void printAreaOnLcd(float area) {
  lcd.setCursor(0, 0);
  lcd.print("Area is: ");
  lcd.setCursor(0, 1);
  lcd.print(area);
  delay(5000);
  lcd.clear();
}

void loop() {
  float radius = askForCircleRadius();
  float area = PI * radius * radius;
  printAreaOnLcd(area);
}
