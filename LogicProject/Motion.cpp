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

  analogWrite(ML1, speedLeft);
  analogWrite(ML2, 0);
}
void Motion:: backward() {
  Speed = 80;
  analogWrite(MR1, 0);
  analogWrite(MR2, Speed);

  analogWrite(ML1, 0);
  analogWrite(ML2, speedLeft);
}

void Motion:: right() {
  Speed = 80;
  analogWrite(MR1, Speed);
  analogWrite(MR2, 0);

  analogWrite(ML1, 0);
  analogWrite(ML2, speedLeft);
}

void Motion:: left() {
  analogWrite(MR1, 0);
  analogWrite(MR2, Speed);

  analogWrite(ML1, speedLeft);
  analogWrite(ML2, 0);
}
void Motion:: Stop() {
  analogWrite(MR1, 0);
  analogWrite(MR2, 0);

  analogWrite(ML1, 0);
  analogWrite(ML2, 0);
}
void Motion:: rightGripper() {
  Speed = 100;
  analogWrite(MR1, Speed);
  analogWrite(MR2, 0);

  analogWrite(ML1, 0);
  analogWrite(ML2, Speed);
}
void Motion:: leftGripper() {
  Speed = 100;
  analogWrite(MR1, 0);
  analogWrite(MR2, Speed);

  analogWrite(ML1, Speed);
  analogWrite(ML2, 0);
}
void Motion:: rightfesa() {
  analogWrite(ML1, Speed + 60);
  analogWrite(MR2, 0);

  analogWrite(MR1, Speed - 30);
  analogWrite(ML2, 0);
}
void Motion:: avoid() {
  Speed = 120;
  Stop();
  delay(100);
  backward();
  delay(150);
  Stop();
  delay(100);
  left();
  delay(600);
  Stop();
  delay(100);
  forward();
  delay(850);
  Stop();
  delay(100);
  right();
  delay(500);
  Stop();
  delay(200);
  forward();
  delay(600);
  right();
  delay(300);
  forward();
  delay(200);
  right();
  delay(300);
  Stop();
  delay(100);
}

