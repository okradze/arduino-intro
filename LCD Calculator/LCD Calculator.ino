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
  Serial.begin(9600);
}

float askForNumber(String line1, String line2) {
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  while(Serial.available() == 0) {}
  float num = Serial.parseFloat();
  lcd.print(num);
  delay(1000);
  lcd.clear();

  return num;
}

String askForOperation() {
  lcd.setCursor(0, 0);
  lcd.print("Which operation");    
  lcd.setCursor(0, 1);   
  lcd.print("do you want?");

  while(Serial.available() == 0) {}
  String operation = Serial.readString();
  lcd.clear();
  return operation;
}

void printErrorOnLcd() {
  lcd.setCursor(0, 0);
  lcd.print("Type correct");
  lcd.setCursor(0, 1);
  lcd.print("operator");
  delay(2000);
  lcd.clear();
}

void printResultOnLcd(float num1, float num2, float result, String operation) {
  lcd.setCursor(0, 0);
  lcd.print(num1);
  lcd.print(" ");
  lcd.print(operation);
  lcd.print(" ");
  lcd.print(num2);
  lcd.print(" = ");
  lcd.print(result);
  delay(5000);
  lcd.clear();
}

void doOperationAndPrint(float num1, float num2, String operation) {
  float result;

  if(operation == "+") {
    result = num1 + num2;
  } else if(operation == "-") {
    result = num1 - num2;
  } else if(operation == "*") {
    result = num1 * num2;
  } else if(operation == "/") {
    result = num1 / num2;
  }

  if(!result) {
    printErrorOnLcd();
  } else {
    printResultOnLcd(num1, num2, result, operation);
  }
}

void loop() {
  float num1 = askForNumber("Enter first", "number: ");
  float num2 = askForNumber("Enter second", "number: ");
  String operation = askForOperation();
  doOperationAndPrint(num1, num2, operation);
}