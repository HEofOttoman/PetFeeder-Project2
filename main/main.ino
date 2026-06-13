#include <RTClib.h>
#include <Wire.h>

//#include <Servo.h>

#include "ServoMotor.h"
#include "LED.h"
#include "Buzzer.h"
#include "LCD.h"
#include "RGB.h"

Buzzer alarmBuzzer(2);
ServoMotor feederServoMotor(3);

// LED redLED(3);
// RGB light(4, 5, 6);

LCD DisplayLCD(0x27, 16, 2);

RTC_DS1307 rtc;
// DateTime feedingTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  rtc.begin();
  alarmBuzzer.begin();
  // redLED.begin();
  feederServoMotor.begin();
  DisplayLCD.begin();
  // light.begin();
  DisplayLCD.displayText("hi");
  // light.enable(true, false, true);
  
  feederServoMotor.setAngle(180);
  alarmBuzzer.beep();

}

void loop() {
  DateTime now = rtc.now();
  // put your main code here, to run repeatedly:

  Serial.print(now.hour());
	Serial.print(':');
	Serial.print(now.minute());
	Serial.print(':');
	Serial.print(now.second());
  // DisplayLCD.display(now.hour());
	// DisplayLCD.lcd.print(':');
	Serial.print(now.minute());
	Serial.print(':');
	Serial.print(now.second());

  // if (now == feedingTime) {
  //   feedAnimal();
  // }

  delay(1000);

}

void feedAnimal() {
  alarmBuzzer.playMelody();
  feederServoMotor.setAngle(90);
}
