int ledPin = 8;
int buttonPin = 12;
bool lightOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonRead = digitalRead(buttonPin);
  Serial.println(buttonRead);

  while(buttonRead == 1) {
    buttonRead = digitalRead(buttonPin);
  }

  while(buttonRead == 0) {
    buttonRead = digitalRead(buttonPin);
  }

  lightOn = !lightOn;

  if(lightOn) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}
