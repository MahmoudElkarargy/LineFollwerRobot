#include "lcd.h"
#include "Arduino.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(26, A0, 29, 31, 33, 35);

void LiquidCrystalDisplay:: init() {
  lcd.begin(16, 2);
  lcd.clear();
}
void LiquidCrystalDisplay:: writeonLCD(String msg) {
  if (last != msg) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Moving ");

  }
  if (msg == "forward") {
    lcd.print("FORWARD");
    lcd.setCursor(0, 1);
    lcd.print("^^^^^^^^^^^^^^^^");
    last = "forward";
  }
  else if (msg == "right") {
    lcd.print("RIGHT");
    lcd.setCursor(0, 1);
    lcd.print(">>>>>>>>>>>>>>>>");
    last = "right";
  }
  else if (msg == "left") {
    lcd.print("LEFT");
    lcd.setCursor(0, 1);
    lcd.print("<<<<<<<<<<<<<<<<");
    last = "left";
  }
  else if (msg == "backward") {
    lcd.print("BACKWARD");
    lcd.setCursor(0, 1);
    lcd.print("VVVVVVVVVVVVVVVV");
    last = "backward";

  }
  else if (msg == "avoid") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Avoiding ");
    lcd.setCursor(0,1);
    lcd.print("obstacle");
    last = "avoid";
  }
  else if (msg == "grap") {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Gripping object");
    last = "grap";
  }
  else if (msg == "stop") {
    lcd.print("STOP");
    lcd.setCursor(0, 1);
    lcd.print("XXXXXXXXXXXXXXXX");
    last = "stop";
  }
}

