#include "ServoMotor.h"

//Constructor
ServoMotor::ServoMotor(int servoPin) {
	pin = servoPin;
	currentAngle = 0;
}

void ServoMotor::begin() {
	servo.attach(pin);
	servo.write(currentAngle);
}

void ServoMotor::setAngle(int angle) {
	angle = constrain(angle, 0, 180);
	currentAngle = angle;
	servo.write(angle);
}

int ServoMotor::getAngle(){
	return currentAngle;
}
