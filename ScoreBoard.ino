#include "library/RGBSegmentDisplay.h"
#include "library/VolleyScore.h"
/*#ifdef __AVR__
  #include <avr/power.h>
#endif*/

#define PIN            D5
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      192

RGBSegmentDisplay segmentDisp(PIN);
VolleyScore score;

void setup() {
  Serial.begin(115200);
  segmentDisp.begin();
  //
}

void loop() {
  delay(2000);
 // Serial.println("1");
  if (Serial.available() > 0) {
    char c = Serial.read();
    switch (c) {
      case '0':
        score.reset();
        break;
      case '1':
        score.addPointTeam1();
        break;
      case '2':
        score.addPointTeam2();
        break;
    }
  }

  if (score.needRefresh()) {
    segmentDisp.setColor(1, 0, 0);
    int team1Point = score.getPointTeam1();
    segmentDisp.setNumber(getFirstDigit(team1Point), 0);
    segmentDisp.setNumber(getSecondDigit(team1Point), 1);
    int team2Point = score.getPointTeam2();
    segmentDisp.setNumber(getFirstDigit(team2Point), 2);
    segmentDisp.setNumber(getSecondDigit(team2Point), 3);

    segmentDisp.setNumber(score.getTeam1WinnedGame(), 4);
    segmentDisp.setNumber(score.getTeam2WinnedGame(), 5);
    segmentDisp.show();
  }
}

int getFirstDigit(int score) {
  return score / 10;
}

int getSecondDigit(int score) {
  return score % 10;
}

