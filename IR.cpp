#include "IR.h"
#include "Arduino.h"
void Ir:: init(){
  pinMode(SL,INPUT);
  pinMode(SC,INPUT);
  pinMode(SR,INPUT);
}
void Ir:: printReadings(){
  Serial.print("Left: ");
  Serial.print(left);
  Serial.print("Center: ");
  Serial.print(center);
  Serial.print("Right: ");
  Serial.println(right);
  delay(200);
}
int Ir:: getLeftReadings(){
  left = digitalRead(SL);
  return left;
}
int Ir:: getCenterReadings(){
  center = digitalRead(SC);
  return center;
}
int Ir:: getRightReadings(){
  right = digitalRead(SR);
  return right;
}

