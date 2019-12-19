#include "Motion.h"
#include "IR.h"
#include "Gripper.h"

#define Signal1 10
#define Signal2 11
#define LCD1 26
#define LCD2 A0
#define LCD3 29
#define LCD4 31
#define LCD5 33
#define LCD6 35

long duration;
int distance;

int left;
int center;
int right;
int distanceLower;
int distanceUpper;

bool isCatched = false;

Motion motion;
Ir ir;
Grip gripper;

void setup() {
  Serial.begin(9600);
  motion.init();
  ir.init();
  gripper.init();
  pinMode(7, OUTPUT); // Sets the trigPin as an Output
  pinMode(6, INPUT); // Sets the echoPin as an Input
  pinMode(8, OUTPUT); // Sets the trigPin as an Output
  pinMode(9, INPUT); // Sets the echoPin as an Input

}

void loop() {
  //  motion.left();

  //  ir.printReadings();

  distanceLower = getDistance(8, 9);
  Serial.print("Distance lower: ");
  Serial.println(distanceLower);

  distanceUpper = getDistance(7, 6);

  Serial.print("Distance upper: ");
  Serial.println(distanceUpper);

  if (distanceLower < 15 && distanceUpper < 15 && isCatched == false) {
    //catch
    Serial.println("catch");
    motion.Stop();
    //    delay(9991000);

    gripper.openGripper();
    isCatched = true;
    while (distanceLower > 4 && distanceUpper > 4) {
      checkLine();
      distanceLower = getDistance(8, 9);
      distanceUpper = getDistance(7, 6);
      Serial.println("bt-check ya abn el 3ars");
    }
    //    motion.forward();
    //    delay(700);
    motion.Stop();
    delay(9991000);


  }
  else if (distanceLower < 10 && isCatched == false ) {
    //avoid
    Serial.println("avoid");
    //          motion.avoid();
  }
  else {
    checkLine();

  }
}





void checkLine() {
  //HIGH --> Black
  left = ir.getLeftReadings();
  center = ir.getCenterReadings();
  right = ir.getRightReadings();

  // W B W
  if (left == LOW && center == HIGH && right == LOW) {
    motion.forward();
    //    Serial.println("Case Forward");
  }
  //W B B
  else if (left == LOW && center == HIGH && right == HIGH) {
    motion.right();
    //    Serial.println("Case Right");
  }
  //B B W
  else if (left == HIGH && center == HIGH && right == LOW) {
    motion.left();
    //    Serial.println("Case left");
  }
  //B B B
  else if (left == HIGH && center == HIGH && right == HIGH) {
    motion.Stop();
    //    Serial.println("Case Stop");
  }
  //W W W
  else if (left == LOW && center == LOW && right == LOW) {
    motion.forward();
    //    Serial.println("Case Gap");
  }
  //make sure cases
  //W W B
  else if (left == LOW && center == LOW && right == HIGH) {
    motion.right();
    //    Serial.println("Case hard right");
  }
  //B W W
  else if (left == HIGH && center == LOW && right == LOW) {
    motion.left();
    //    Serial.println("Case hard left");
  }
  //B W B
  else if (left == HIGH && center == LOW && right == HIGH) {
    motion.Stop();
    //    Serial.println("WTF?");
  }


}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  //  Serial.print("Distance: ");
  //  Serial.println(distance);
  return distance;
}
