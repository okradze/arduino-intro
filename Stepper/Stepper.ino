#include <Stepper.h>
int stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int motSpeed = 10;
int dt = 10;

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
}

void loop() {
  myStepper.step(stepsPerRevolution);
  delay(dt);
  myStepper.step(-stepsPerRevolution);
  delay(dt);
}
