#include <LiquidCrystal.h>
const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Watch me count");
  lcd.setCursor(0, 1);

  for(int i = 1; i <= 10; i++) {
    lcd.setCursor(0,1);
    lcd.print(i);
    delay(500);
  }

  lcd.clear();
}
