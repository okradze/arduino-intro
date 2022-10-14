const int triggerPin = 12;
const int echoPin = 11;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  int pingTravelTime = pulseIn(echoPin, HIGH);
  float distance = (0.034 * pingTravelTime) / 2;

  Serial.print(0);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(",");
  Serial.println(10);
  delay(25);
} 
