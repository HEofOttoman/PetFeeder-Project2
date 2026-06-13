#ifndef RGB_H
#define RGB_H

#include <Arduino.h>

class RGB {
	private:
		int _redPin;
    int _greenPin;
    int _bluePin;

		bool enableState;
		
	public:
		RGB(int red, int green, int blue); // LED
		
		void begin(); 
		
		void enable(bool redEnable, bool greenEnable, bool blueEnable); 

		void disable();
		
		int getState(); // Returns enabled as integer
};
#endif