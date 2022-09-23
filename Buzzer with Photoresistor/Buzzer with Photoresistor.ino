int lightPin = A3;
int buzzerPin = 8;

void setup() {
  pinMode(lightPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(lightPin);
  int delayT = (9. / 550.) * lightVal - (9. * 200. / 550.) + 1.;

    digitalWrite(buzzerPin, HIGH);
    delay(delayT);
    digitalWrite(buzzerPin, LOW);
    delay(delayT);
}
