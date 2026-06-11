#include "Buzzer.h"

//Constructor
Buzzer::Buzzer(int buzzerPin) {
	pin = buzzerPin;
}

void Buzzer::begin() {
	pinMode(pin, OUTPUT);
}

void Buzzer::beep() {
	tone(pin, 415);
	delay(500);
	noTone(pin);
}

void Buzzer::stopBuzzer() {
	noTone(pin);
}

void Buzzer::playMelody() {
	int melody[] = { 415, 370, 330, 247, 330, 415, 370, 247 };
	int durations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };
	digitalWrite(pin, HIGH);

	for (int i = 0; i < 8; i++) {
		tone(pin, melody[i], durations[i]);
		delay(durations[i] + 50);
	}
	noTone(pin);
}

// int LED::getState() {
// 	return enableState;
// }
