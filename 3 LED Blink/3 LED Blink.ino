int redPin = 8;
int greenPin = 9;
int bluePin = 10;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  for(int i = 0; i < 5; i++) {
    digitalWrite(redPin, HIGH);
    delay(100);
    digitalWrite(redPin, LOW);
    delay(100);
  }

  for(int i = 0; i < 10; i++) {
    digitalWrite(greenPin, HIGH);
    delay(100);
    digitalWrite(greenPin, LOW);
    delay(100);
  }

  for(int i = 0; i < 15; i++) {
    digitalWrite(bluePin, HIGH);
    delay(100);
    digitalWrite(bluePin, LOW);
    delay(100);
  }
}
