#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
	private:
		int pin;
		int melody[];
		
	public:
		Buzzer(int buzzerPin); // Servo motor
		
		void begin(); 
		
		void playMelody(); 
		
		//int getAngle(); 
    // Returns current angle as integer
};
#endif