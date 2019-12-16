#include "lcd.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

void LiquidCrystalDisplay:: init() {
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//  lcd.begin(16, 2);
//  lcd.clear();
}
void LiquidCrystalDisplay:: writeonLCD(String msg){
//  lcd.setCursor(0,0);
  if(msg == ""){
    
  }
}

