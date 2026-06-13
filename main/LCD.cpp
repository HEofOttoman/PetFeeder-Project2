#include "LCD.h"

LCD::LCD(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows): lcd(lcd_Addr, lcd_cols, lcd_rows) {
	address = lcd_Addr;
	columns = lcd_cols;
	rows = lcd_rows;
	

}

void LCD::begin() {
  lcd.init();
  lcd.backlight();
	lcd.begin(16, 2);
}

void LCD::displayText(char* text) {
	lcd.setCursor(0, 0);
	lcd.print(text);
}

void LCD::clear() {
	lcd.clear();
	
}