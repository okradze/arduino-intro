int redPin = 8;
int greenPin = 9;
int bluePin = 10;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
    digitalWrite(redPin, HIGH);
    delay(200);
    digitalWrite(redPin, LOW);
    delay(200);

    digitalWrite(greenPin, HIGH);
    delay(200);
    digitalWrite(greenPin, LOW);
    delay(200);

    digitalWrite(bluePin, HIGH);
    delay(200);
    digitalWrite(bluePin, LOW);
    delay(200);
}
