String message = "How many blinks do you want: ";
int ledPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print(message);
  while(Serial.available() == 0) {}

  int numOfBlinks = Serial.parseInt();
  Serial.println(numOfBlinks);

  for(int i = 1; i <= numOfBlinks; i++) {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}
