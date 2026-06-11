#ifndef LED_H
#define LED_H

#include <Arduino.h>

class LED {
	private:
		int pin;
		bool enableState;
		
	public:
		LED(int ledPin); // LED
		
		void begin(); 
		
		void enable(bool on); 
		
		int getState(); // Returns enabled as integer
};
#endif