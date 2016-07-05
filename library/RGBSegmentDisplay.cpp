#include "RGBSegmentDisplay.h"

#define NUMPIXELS      192

RGBSegmentDisplay::RGBSegmentDisplay()
{
  pinMode(PIN, OUTPUT);
  _red = 1;
  _green = 0;
  _blue = 0;
  _rgbColor = RgbColor(1, 0, 0);
  _offColor = RgbColor(0, 0, 0);
  _digitSelectedCharArray;
}

void RGBSegmentDisplay::begin() {
  _strip.Begin();
  _strip.Show();
}

void RGBSegmentDisplay::setColor(int red, int green, int blue) {
	_red = red;
	_green = green;
	_blue = blue;
	_rgbColor = RgbColor(red, green, blue);
}

void RGBSegmentDisplay::setNumber(int number, int index) {
	if (number > 9) {
		return;
	}
  _digitSelectedCharArray[index] = number;
  for (int i = 0; i < 6; i++) {
    int digitToDisplay = _digitSelectedCharArray[i];
    for (int j = 0; j < 28; j++) {
      bool pixelOn = _numberArray[digitToDisplay][j];
      int pixelAddress = j + (i * 28);
      if (pixelOn) {
        _strip.SetPixelColor(pixelAddress, _rgbColor);  
      } else {
        _strip.SetPixelColor(pixelAddress, _offColor);
      }
    }
  }
}

void RGBSegmentDisplay::show() {
	_strip.Show();
}