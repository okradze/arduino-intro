int readPin = A5;
float V2 = 0;
int delayTime = 500;

void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  V2 = analogRead(readPin) * (5. / 1023.);
  Serial.println(V2);
  delay(delayTime);
}
