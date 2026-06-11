#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

class ServoMotor {
	private:
		int pin;
		Servo servo;
		int currentAngle;
		
	public:
		ServoMotor(int servoPin); // Servo motor
		
		void begin(); 
		
		void setAngle(int angle); 
		
		int getAngle(); // Returns current angle as integer
};
#endif