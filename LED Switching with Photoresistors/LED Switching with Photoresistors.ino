int lightPin = A0;
int redPin = 8;
int greenPin = 9;

void setup() {
  pinMode(lightPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightVal = analogRead(lightPin);

  if(lightVal >= 250) {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);    
  } else {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);     
  }
}
