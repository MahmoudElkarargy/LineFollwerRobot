#include "Gripper.h"
#include "Arduino.h"
#include <Servo.h>
Servo myservo;

void Grip:: init(){
  pinMode(Signal,OUTPUT);
  myservo.attach(Signal);
  myservo.write(40); 
}

void Grip:: openGripper(){
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}


void Grip:: closeGripper(){
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}
