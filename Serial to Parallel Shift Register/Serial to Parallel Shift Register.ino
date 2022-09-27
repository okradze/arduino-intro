int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 250;

byte LED1s = B10101010;
byte LED2s = B01010101;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED1s);
  digitalWrite(latchPin, HIGH);
  delay(dt);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, LED2s);
  digitalWrite(latchPin, HIGH);
  delay(dt);
}
