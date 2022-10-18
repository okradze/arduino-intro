#include "LedControl.h"
LedControl lc = LedControl(12,11,10,1);

// smiley face
byte smileyFace[8]= {B00111100,B01000010,B10100101,B10000001,B10111101,B10011001,B01000010,B00111100};
// happy face
byte happyFace[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};
// neutral face
byte neutralFace[8]={B00111100, B01000010,B10100101,B10000001,B10000001,B10111101,B01000010,B00111100};
// sad face
byte sadFace[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};

byte* faces[4] = {sadFace, neutralFace, happyFace, smileyFace};
int delayTime = 1000;

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  Serial.begin(9600);
}

void loop(){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 8; j++) {
      lc.setRow(0, j, faces[i][j]);
    }
    delay(delayTime);
  }
}
