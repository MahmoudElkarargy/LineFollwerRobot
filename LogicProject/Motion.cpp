#include "Motion.h"
#include "Arduino.h"

void Motion:: init() {
  pinMode(MR1, OUTPUT);
  pinMode(MR2, OUTPUT);
  pinMode(ML1, OUTPUT);
  pinMode(ML2, OUTPUT);

}
void Motion:: forward() {
  analogWrite(MR1, Speed);
  analogWrite(MR2, 0);

  analogWrite(ML1, Speed);
  analogWrite(ML2, 0);
}
void Motion:: backward() {
  analogWrite(MR1, 0);
  analogWrite(MR2, Speed);

  analogWrite(ML1, 0);
  analogWrite(ML2, Speed);
}

void Motion:: right() {
  analogWrite(MR1, Speed);
  analogWrite(MR2, 0);

  analogWrite(ML1, 0);
  analogWrite(ML2, Speed);
}

void Motion:: left() {
  analogWrite(MR1, 0);
  analogWrite(MR2, Speed);

  analogWrite(ML1, Speed);
  analogWrite(ML2, 0);
}
void Motion:: Stop() {
  analogWrite(MR1, 0);
  analogWrite(MR2, 0);

  analogWrite(ML1, 0);
  analogWrite(ML2, 0);
}
void Motion:: avoid() {
  Speed = 60;
  Stop();
  delay(100);
  left();
  delay(500);
  forward();
  delay(900);
  right();
  delay(400);
//  Stop();
//  delay(99999);
  
  forward();
  delay(1600);
  right();
  delay(400);
  forward();
  delay(700);
  left();
  delay(600);
//  Stop();
//  delay(99999);
  
  
  
}

