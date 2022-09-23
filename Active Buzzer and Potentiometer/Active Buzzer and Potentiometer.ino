int buzzPin = 8;
int potPin = A5;

void setup() {
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int potVal = analogRead(potPin);

  if(potVal > 1000) {
    digitalWrite(buzzPin, HIGH);
    delay(100);
    digitalWrite(buzzPin, LOW);
    delay(100);
  } else {
    digitalWrite(buzzPin, LOW);
  }
}
