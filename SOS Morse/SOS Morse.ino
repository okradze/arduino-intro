int ledPin = 8;
int dit = 250;
int dah = 750;
int longW = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(dit);
  digitalWrite(ledPin, LOW);
  delay(dit);

  digitalWrite(ledPin, HIGH);
  delay(dit);
  digitalWrite(ledPin, LOW);
  delay(dit);

  digitalWrite(ledPin, HIGH);
  delay(dit);
  digitalWrite(ledPin, LOW);
  delay(dit);

  digitalWrite(ledPin, HIGH);
  delay(dah);
  digitalWrite(ledPin, LOW);
  delay(dah);

  digitalWrite(ledPin, HIGH);
  delay(dah);
  digitalWrite(ledPin, LOW);
  delay(dah);

  digitalWrite(ledPin, HIGH);
  delay(dah);
  digitalWrite(ledPin, LOW);
  delay(dah);

  digitalWrite(ledPin, HIGH);
  delay(dit);
  digitalWrite(ledPin, LOW);
  delay(dit);

  digitalWrite(ledPin, HIGH);
  delay(dit);
  digitalWrite(ledPin, LOW);
  delay(dit);

  digitalWrite(ledPin, HIGH);
  delay(dit);
  digitalWrite(ledPin, LOW);
  delay(dit);

  delay(longW);
}
