const int speedPin = 3;
const int directionPin1 = 4;
const int directionPin2 = 5;
const int joyYPin = A1;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin1, OUTPUT);
  pinMode(directionPin2, OUTPUT);
  pinMode(joyYPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int joyY = analogRead(joyYPin);
  
  if(joyY < 493) {
    digitalWrite(directionPin1, LOW);
    digitalWrite(directionPin2, HIGH);
    int speed = (-255. / 493.) * joyY + 255;
    analogWrite(speedPin, speed);
  } else {
    digitalWrite(directionPin1, HIGH);
    digitalWrite(directionPin2, LOW);
    int speed = (255. / 530.) * joyY - 237.198112725;
    analogWrite(speedPin, speed);
  }
}
