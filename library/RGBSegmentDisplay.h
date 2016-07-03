#ifndef RGBSegmentDisplay_h
#define RGBSegmentDisplay_h

#define NUMPIXELS   192
#define PIN			14

#include <Arduino.h>
#include <NeoPixelBus.h> //https://github.com/adafruit/Adafruit_NeoPixel

static NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> _strip(NUMPIXELS, PIN);
class RGBSegmentDisplay {
	public:
		RGBSegmentDisplay(int pin);
		void setColor(int red, int green, int blue);
		void setNumber(int number, int index);
		void begin();
		void show();
	private:
		int _red;
		int _green;
		int _blue;
		int _digitSelectedCharArray[6] = {0, 0, 0, 0, 0, 0};
		RgbColor _rgbColor;
		RgbColor _offColor;
		//NeoPixelBus<NeoGrbFeature, NeoEsp8266BitBang800KbpsMethod> _strip;
		const bool _numberArray [10][28] = {
			  //1, 1, 1, 1 a line
			  //0, 0, 0, 0 a not line
			 //0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
			  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,0 ,0 ,0},//number 0
			  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0},//number 1
			  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//number 2
			  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},//number 3
			  {1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},//number 4
			  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1},//number 5
			  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//number 6
			  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},//number 7
			  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 ,1 ,1 ,1},//number 8
			  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 ,0 ,0 ,0, 1 ,1 ,1 ,1},//number 9
			};
};	
#endif
