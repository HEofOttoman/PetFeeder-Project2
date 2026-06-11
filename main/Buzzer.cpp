#include "Buzzer.h"

//Constructor
Buzzer::Buzzer(int buzzerPin) {
	pin = buzzerPin;
	//currentAngle = 0;
}

void Buzzer::begin() {
	pinMode(pin, OUTPUT);
}

void Buzzer::playMelody() {
	digitalWrite(pin, HIGH);

}

// int LED::getState() {
// 	return enableState;
// }
