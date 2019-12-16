#include "Motion.h"
#include "IR.h"


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

Motion motion;
Ir ir;

void setup() {
  Serial.begin(9600);
  motion.init();
  ir.init();
  pinMode(7, OUTPUT); // Sets the trigPin as an Output
  pinMode(6, INPUT); // Sets the echoPin as an Input
  pinMode(8, OUTPUT); // Sets the trigPin as an Output
  pinMode(9, INPUT); // Sets the echoPin as an Input

}

void loop() {
  //  motion.left();
  left = ir.getLeftReadings();
  center = ir.getCenterReadings();
  right = ir.getRightReadings();
  //  ir.printReadings();

  distanceLower = getDistance(7, 6);
//  Serial.print("Distance lower: ");
//  Serial.println(distanceLower);

  distanceUpper = getDistance(8, 9);

//  Serial.print("Distance upper: ");
//  Serial.println(distanceUpper);

  if (distanceLower < 5 && distanceUpper < 5) {
        //catch
    Serial.println("catch");
  }
  else if (distanceLower < 5) {
    //avoid
    Serial.println("avoid");
          motion.avoid();
//    motion.Stop();

  }
  else {
    checkLine();

  }
}





void checkLine() {
  //HIGH --> Black
  // W B W
  if (left == LOW && center == HIGH && right == LOW) {
    motion.forward();
    Serial.println("Case Forward");
  }
  //W B B
  else if (left == LOW && center == HIGH && right == HIGH) {
    motion.right();
    Serial.println("Case Right");
  }
  //B B W
  else if (left == HIGH && center == HIGH && right == LOW) {
    motion.left();
    Serial.println("Case left");
  }
  //B B B
  else if (left == HIGH && center == HIGH && right == HIGH) {
    motion.Stop();
    Serial.println("Case Stop");
  }
  //W W W
  else if (left == LOW && center == LOW && right == LOW) {
    motion.forward();
    Serial.println("Case Gap");
  }
  //make sure cases
  //W W B
  else if (left == LOW && center == LOW && right == HIGH) {
    motion.right();
    Serial.println("Case hard right");
  }
  //B W W
  else if (left == HIGH && center == LOW && right == LOW) {
    motion.left();
    Serial.println("Case hard left");
  }
  //B W B
  else if (left == HIGH && center == LOW && right == HIGH) {
    motion.Stop();
    Serial.println("WTF?");
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
