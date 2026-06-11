#include <RTClib.h>
#include <Wire.h>

//#include <Servo.h>

#include "ServoMotor.h"
#include "LED.h"
#include "Buzzer.h"
// #include "LCD.cpp"

Buzzer alarmBuzzer(2);
LED redLED(3);
ServoMotor feederServoMotor(4);

RTC_DS1307 rtc;
DateTime feedingTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  alarmBuzzer.begin();
  redLED.begin();
  feederServoMotor.begin();

}

void loop() {
  DateTime now = rtc.now();
  // put your main code here, to run repeatedly:

  Serial.print(now.hour());
	Serial.print(':');
	Serial.print(now.minute());
	Serial.print(':');
	Serial.print(now.second());

  if (now == feedingTime) {
    feedAnimal();
  }

  delay(1000);

}

void feedAnimal() {
  feederServoMotor.setAngle(90);
}
