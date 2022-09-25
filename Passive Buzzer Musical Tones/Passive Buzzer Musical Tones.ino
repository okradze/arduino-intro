#include <pitches.h>
int buzzPin = 12;
int melody [] = { NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
int duration = 500;

void setup() {
}

void loop() {
  for(int i = 0; i < 8; i++) {
    tone(buzzPin, melody[i], duration);
    delay(1000);
  }

  delay(2000);
}
