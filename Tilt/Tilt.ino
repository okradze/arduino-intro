int tiltPin = 2;
int redPin = 7;
int greenPin = 12;

void setup() {
  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int tiltVal = digitalRead(tiltPin);

  if(tiltVal == 0) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  } else if(tiltVal == 1) {
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }
  
  delay(100);
}
