#ifndef LCD_H
#define LCD_H
#include "Arduino.h"
#include <LiquidCrystal.h>


class LiquidCrystalDisplay
{
  public:
    void init();
    String last = "";
    void writeonLCD(String);


};
#endif // LCD_H

