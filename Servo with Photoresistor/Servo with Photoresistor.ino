#include <Servo.h>
int lightPin = A3;
int servoPin = 9;
Servo servo;

void setup() {
  pinMode(lightPin, INPUT);
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  int lightVal = analogRead(lightPin);
  int pos = (180.0 / 350.) * lightVal;
  
  servo.write(pos);
  delay(500);
}
