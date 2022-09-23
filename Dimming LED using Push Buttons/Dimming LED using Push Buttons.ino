int button1Pin = 8;
int button2Pin = 9;
int ledPin = 11;
int buzzPin = 12;
int ledBrightness = 0;

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void buzzFor(int ms) {
  digitalWrite(buzzPin, HIGH);
  delay(ms);
  digitalWrite(buzzPin, LOW);
}

void loop() {
  int button1Val = digitalRead(button1Pin);
  int button2Val = digitalRead(button2Pin);
  Serial.print("Button 1: ");
  Serial.print(button1Val);
  Serial.print(" Button 2: ");
  Serial.println(button2Val);

  if(button1Val == 0) {
    ledBrightness -= 3;
  }

  if(button2Val == 0) {
    ledBrightness += 3;
  }

  if(ledBrightness > 255) {
    ledBrightness = 255;
    buzzFor(500);
  }

  if(ledBrightness < 0) {
    ledBrightness = 0;
    buzzFor(500);
  }

  analogWrite(ledPin, ledBrightness);
}
