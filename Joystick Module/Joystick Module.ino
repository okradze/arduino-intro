int xPin = A0;
int yPin = A1;
int sPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  digitalWrite(sPin, HIGH);
}

void loop() {
  int x = analogRead(xPin);
  int y = analogRead(yPin);
  int s = digitalRead(sPin);
  delay(200);
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.print(y);
  Serial.print(", Switch: ");
  Serial.println(s);
}