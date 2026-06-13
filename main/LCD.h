#ifndef LCD_H
#define LCD_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


class LCD {
  private:
    LiquidCrystal_I2C lcd;
    uint8_t address;
    uint8_t columns;
    uint8_t rows;

  public:
    LCD(uint8_t lcd_Addr, uint8_t lcd_cols, uint8_t lcd_rows);

    void begin();

    void displayText(char* text);

    void clear();
};
#endif