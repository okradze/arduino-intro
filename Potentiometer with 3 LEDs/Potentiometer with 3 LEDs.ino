int readPin = A5;
int redLedPin = 8;
int yellowLedPin = 9;
int greenLedPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(readPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  int val = analogRead(readPin);
  float v2 = (5. / 1023.) * val;
  Serial.print("Potentiometer's voltage is ");
  Serial.println(v2);

  if (v2 > 4) {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, LOW);
  } else if(v2 <= 4 && v2 > 3) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
  } else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
  }

  delay(500);
}
