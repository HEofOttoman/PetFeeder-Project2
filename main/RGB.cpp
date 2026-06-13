#include "RGB.h"

//Constructor
RGB::RGB(int red, int green, int blue) {
	_redPin = red;
  _greenPin = green;
  _bluePin = blue;

	enableState = false;
}

void RGB::begin() {
	pinMode(_redPin, OUTPUT);
  pinMode(_greenPin, OUTPUT);
  pinMode(_bluePin, OUTPUT);
}

void RGB::enable(bool redEnable, bool greenEnable, bool blueEnable) {
	digitalWrite(_redPin, redEnable);
	digitalWrite(_greenPin, greenEnable);
	digitalWrite(_bluePin, blueEnable);

}

int RGB::getState() {
	return enableState;
}
