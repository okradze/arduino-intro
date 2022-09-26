const int speedPin = 3;
const int directionPin1 = 4;
const int directionPin2 = 5;
const int motorSpeed = 255;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(directionPin1, LOW);
  digitalWrite(directionPin2, HIGH);
  analogWrite(speedPin, motorSpeed);
}
