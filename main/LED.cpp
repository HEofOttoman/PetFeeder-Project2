#include "LED.h"

//Constructor
LED::LED(int ledPin) {
	pin = ledPin;
	enableState = false;
}

void LED::begin() {
	pinMode(pin, OUTPUT);
}

void LED::enable(bool enable) {
	digitalWrite(pin, enable);

}

int LED::getState() {
	return enableState;
}
