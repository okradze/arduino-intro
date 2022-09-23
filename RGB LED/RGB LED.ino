int redPin = 9;
int greenPin = 6;
int bluePin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.print("What colour do you want?: ");
  while(Serial.available() == 0) {}

  String color = Serial.readString();

  if(color == "red") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if(color == "green") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if(color == "blue") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (color == "yellow") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 100);
    analogWrite(bluePin, 0);
  } else if (color == "off") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
}
