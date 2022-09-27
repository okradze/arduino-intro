int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 100;

byte LEDs = 0;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  Serial.println(LEDs);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
  digitalWrite(latchPin, HIGH);
  LEDs += 1;
  delay(dt);
}
