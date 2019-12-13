#include "Motion.h"
#include "Arduino.h"

void Motion:: init(){
  pinMode(MR1,OUTPUT);
  pinMode(MR2,OUTPUT);
  pinMode(ML1,OUTPUT);
  pinMode(ML2,OUTPUT);
  
}
void Motion:: forward(){
  analogWrite(MR1,Speed);
  analogWrite(MR2,0);

  analogWrite(ML1,Speed);
  analogWrite(ML2,0);
}
void Motion:: backward(){
  analogWrite(MR1,0);
  analogWrite(MR2,Speed);

  analogWrite(ML1,0);
  analogWrite(ML2,Speed);
}

void Motion:: right(){
  analogWrite(MR1,Speed);
  analogWrite(MR2,0);

  analogWrite(ML1,0);
  analogWrite(ML2,Speed);
}

void Motion:: left(){
  analogWrite(MR1,0);
  analogWrite(MR2,Speed);

  analogWrite(ML1,Speed);
  analogWrite(ML2,0);
}
void Motion:: Stop(){
  analogWrite(MR1,0);
  analogWrite(MR2,0);

  analogWrite(ML1,0);
  analogWrite(ML2,0);
}
void Motion:: avoid(){
  Stop();
  delay(100);
  backward();
  delay(300);
  left();
  delay(500);
  forward();
  delay(1000);
  right();
  delay(500);
  forward();
  delay(3000);
  right();
  delay(500);
  forward();
  delay(1000);
  left();
  delay(500);
}

