const int decButtonPin = 8;
const int incButtonPin = 9;

const int motorSpeedPin = 3;
const int motorDirection1Pin = 4;
const int motorDirection2Pin = 5;

const int baseMotorSpeed = 100;
const int motorSpeedInterval = 10;
int motorSpeed = 0;

const int buttonDelay = 300;

void setup() {
  pinMode(decButtonPin, INPUT_PULLUP);
  pinMode(incButtonPin, INPUT_PULLUP);
  pinMode(motorSpeedPin, OUTPUT);
  pinMode(motorDirection1Pin, OUTPUT);
  pinMode(motorDirection2Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int incButton = digitalRead(incButtonPin);
  int decButton = digitalRead(decButtonPin);

  if (incButton == LOW) {
    motorSpeed += motorSpeedInterval;

    if (motorSpeed > 255) {
      motorSpeed = 255;
    } else if (motorSpeed > 0 && motorSpeed < baseMotorSpeed) {
      motorSpeed = baseMotorSpeed;
    } else if(motorSpeed > -baseMotorSpeed && motorSpeed < 0) {
      motorSpeed = 0;
    }
    delay(buttonDelay);
  }

  if (decButton == LOW) {
    motorSpeed -= motorSpeedInterval;

    if (motorSpeed < -255) {
      motorSpeed = -255;
    } else if(motorSpeed > -baseMotorSpeed && motorSpeed < 0) {
      motorSpeed = -baseMotorSpeed;
    } else if(motorSpeed < baseMotorSpeed && motorSpeed > 0) {
      motorSpeed = 0;
    }
    delay(buttonDelay);
  }


  if(motorSpeed > 0) {
    digitalWrite(motorDirection1Pin, LOW);
    digitalWrite(motorDirection2Pin, HIGH);
  } else if(motorSpeed < 0) {
    digitalWrite(motorDirection1Pin, HIGH);
    digitalWrite(motorDirection2Pin, LOW);
  }

  analogWrite(motorSpeedPin, abs(motorSpeed));
}