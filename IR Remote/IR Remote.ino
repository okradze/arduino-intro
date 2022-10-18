#include <IRremote.h>
int IRpin = 9;
IRrecv IR(IRpin);
decode_results cmd;
String myCom;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  while (IR.decode(&cmd) == 0) {}
  Serial.println(cmd.value, HEX);
  delay(100);
  IR.resume();
}