#ifndef LCD_H
#define LCD_H
#include "Arduino.h"
#include <LiquidCrystal.h>


class LiquidCrystalDisplay
{
  public:
    void init();
    const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
    void writeonLCD(String);

    
};
#endif // LCD_H

