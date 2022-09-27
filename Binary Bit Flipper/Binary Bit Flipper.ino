int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 500;

byte LEDs = B10101010;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
  digitalWrite(latchPin, HIGH);
  LEDs = 255 - LEDs;
  delay(dt);
}
