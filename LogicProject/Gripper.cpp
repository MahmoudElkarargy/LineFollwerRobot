#include "Gripper.h"
#include "Arduino.h"
#include <Servo.h>
Servo myservo;
Servo upperServo;

void Grip:: init(int Signal) {
  pinMode(Signal, OUTPUT);
  myservo.attach(Signal);
  myservo.write(40);
}

void Grip:: initUp(int Signal) {
  pinMode(Signal, OUTPUT);
  upperServo.attach(Signal);
  upperServo.write(180);
}

void Grip:: openGripper() {
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void Grip:: closeGripperUp() {
  for (int pos = 100; pos <= 180; pos += 1) { // goes from 100 degrees to 180 degrees
    // in steps of 1 degree
    upperServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void Grip:: closeGripper() {
  for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void Grip:: openGripperUp() {
  for (int pos = 180; pos >= 100; pos -= 1) { // goes from 180 degrees to 100 degrees
    upperServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
