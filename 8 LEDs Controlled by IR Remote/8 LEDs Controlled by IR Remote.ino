#include <IRremote.h>
const int IRpin = 7;
IRrecv IR(IRpin);
decode_results cmd;
const int latchPin = 11;
const int clockPin = 9;
const int dataPin = 12;
const int dt = 250;
byte leds = B00000000;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  IR.enableIRIn();
  changeLeds(leds);
}

// Reusable function to write data to Parallel Shift Register
void changeLeds(byte data) {
  digitalWrite(latchPin, LOW);
  leds = data;
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  digitalWrite(latchPin, HIGH);
}

// Toggles each Led by position
void toggleLed(int index) {
  int val = bitRead(leds, index);
  
  if (val == 1) {
    bitClear(leds, index);
  } else if (val == 0) {
    bitSet(leds, index);
  }

  changeLeds(leds);
}

void loop() {
  while (IR.decode(&cmd) == 0) {}

  Serial.println(cmd.value, HEX);

  if (cmd.value == 0xFFA25D) {
    if(leds < 255) {
      changeLeds(B11111111);
    } else {
      changeLeds(B00000000);
    }
  } else if(cmd.value == 0xFFE21D) {
    changeLeds(B00000000);
  } else if (cmd.value == 0xFF30CF) {
    toggleLed(7);
  } else if (cmd.value == 0xFF18E7) {
    toggleLed(6);
  } else if (cmd.value == 0xFF7A85) {
    toggleLed(5);
  } else if (cmd.value == 0xFF10EF) {
    toggleLed(4);
  } else if (cmd.value == 0xFF38C7) {
    toggleLed(3);
  } else if (cmd.value == 0xFF5AA5) {
    toggleLed(2);
  } else if (cmd.value == 0xFF42BD) {
    toggleLed(1);
  } else if (cmd.value == 0xFF4AB5) {
    toggleLed(0);
  }

  delay(dt);
  IR.resume();
}