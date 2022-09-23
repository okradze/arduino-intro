int greenPin = 10;
int readPin = A5;

void setup() {
  pinMode(greenPin, OUTPUT);
}

void loop() {
  int readVal = analogRead(readPin);
  int val = readVal * (255. / 1023.);
  analogWrite(greenPin, val);
}
