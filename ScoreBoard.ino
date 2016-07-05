#include "library/RGBSegmentDisplay.h"
#include "library/VolleyScore.h"
/*#ifdef __AVR__
  #include <avr/power.h>
#endif*/

#//define PIN            D5 //Pin14 <- Define in RGBSegmentDisplay.h (template problem)
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      192

RGBSegmentDisplay segmentDisp;
VolleyScore score;

void setup() {
  Serial.begin(115200);
  segmentDisp.setColor(1, 0, 0);
  segmentDisp.begin();
  score.reset();
}

int stringToInt(int startIndex, int endIndex, String commandIn) {
  return commandIn.substring(startIndex, endIndex).toInt();
}

int getFirstDigit(int score) {
  return score / 10;
}

int getSecondDigit(int score) {
  return score % 10;
}

String receivedCommand;
void loop() {
  delay(2000);
  // Serial.println("1");
  while (Serial.available()) {
    delay(3);
    if (Serial.available() > 0) {
      char c = Serial.read();
      receivedCommand += c;
    }
  }

  if (receivedCommand.startsWith("1pT1")) {
    score.addPointTeam1();
  }
  if (receivedCommand.startsWith("1pT2")) {
    score.addPointTeam2();
  }
  if (receivedCommand.startsWith("reset")) {
    score.reset();
  }
  if (receivedCommand.startsWith("color") && receivedCommand.length() == 14) { //no LN&CR
    segmentDisp.setColor(stringToInt(5, 8, receivedCommand), stringToInt(8, 11, receivedCommand), stringToInt(11, 14, receivedCommand));
    segmentDisp.show();
  }

  receivedCommand = "";
  if (score.needRefresh()) {
    int team1Point = score.getPointTeam1();
    //TODO reactivate and delete following line
    // to debug with one 7 segment character
    //segmentDisp.setNumber(getFirstDigit(team1Point), 0);
    segmentDisp.setNumber(getSecondDigit(team1Point), 0);
    segmentDisp.setNumber(getSecondDigit(team1Point), 1);
    
    int team2Point = score.getPointTeam2();
    segmentDisp.setNumber(getFirstDigit(team2Point), 2);
    segmentDisp.setNumber(getSecondDigit(team2Point), 3);

    segmentDisp.setNumber(score.getTeam1WonGame(), 4);
    segmentDisp.setNumber(score.getTeam2WonGame(), 5);
    segmentDisp.show();
  }
}

