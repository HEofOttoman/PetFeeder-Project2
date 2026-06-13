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
DateTime feedingTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("System Booting");
  for(int i = 0; i< 10; i++){
    Serial.print(".");
    delay(400);
  }

  // rtc.begin();
  if (!rtc.begin()){
    Serial.println("rtc failed init, please restart");
    while(1);
  }
  else {
    Serial.println("rtc BOOTED FINALLY!!!");
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
  alarmBuzzer.begin();
  // redLED.begin();
  feederServoMotor.begin();
  DisplayLCD.begin();
  // light.begin();
  DisplayLCD.displayText("Booting success!");
  // light.enable(true, false, true);
  
  feederServoMotor.setAngle(180);
  alarmBuzzer.beep();

  delay(1000);
  DisplayLCD.clear();

}

void loop() {
  DateTime now = rtc.now();
  // put your main code here, to run repeatedly:

  Serial.print(now.hour());
	Serial.print(':');
	Serial.print(now.minute());
	Serial.print(':');
	Serial.print(now.second());
	Serial.print(':');
	Serial.print(now.minute());
	Serial.print(':');
	Serial.println(now.second());

  DisplayLCD.displayText(now.hour());
  DisplayLCD.displayText(':');
	DisplayLCD.displayText(now.minute());
	DisplayLCD.displayText(':');
	DisplayLCD.displayText(now.second());
	DisplayLCD.displayText(':');
	DisplayLCD.displayText(now.minute());
	DisplayLCD.displayText(':');
	DisplayLCD.displayText(now.second());

  if (now == feedingTime) {
    feedAnimal();
  }

  delay(1000);

}

void feedAnimal() {
  alarmBuzzer.playMelody();
  feederServoMotor.setAngle(90);
}
