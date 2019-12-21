#include "Motion.h"
#include "IR.h"
#include "Gripper.h"
#include "lcd.h"

long duration;
int distance;

int left;
int center;
int right;
int distanceLower;
int distanceUpper;


Motion motion;
Ir ir;
Grip gripperOpenClose;
Grip gripperUp;

LiquidCrystalDisplay LCD;
bool flag = true;
bool flagObj = true;

void setup() {
  Serial.begin(9600);
  motion.init();
  ir.init();
  gripperOpenClose.init(10);
  gripperUp.initUp(11);
  LCD.init();
  pinMode(7, OUTPUT); // Sets the trigPin as an Output
  pinMode(6, INPUT); // Sets the echoPin as an Input
  pinMode(8, OUTPUT); // Sets the trigPin as an Output
  pinMode(9, INPUT); // Sets the echoPin as an Input


}

void loop() {
  //  ir.printReadings();

  distanceLower = getDistance(7, 6);
  Serial.print("Distance lower: ");
  Serial.println(distanceLower);

  distanceUpper = getDistance(8, 9);

  Serial.print("Distance upper: ");
  Serial.println(distanceUpper);

  if (distanceLower < 18 && distanceUpper < 18 && flag) {
    //catch
    Serial.println("catch");
    LCD.writeonLCD("grap");
    motion.Stop();
    delay(100);
    motion.backward();
    delay(200);
    motion.Stop();
    gripperUp.openGripperUp();
    delay(100);
    gripperOpenClose.openGripper();
    while (distanceLower > 9 ) {
      checkLine();
      distanceLower = getDistance(7, 6);
      distanceUpper = getDistance(8, 9);
    }
    motion.Stop();
    gripperOpenClose.closeGripper();
    delay(1000);
    gripperUp.closeGripperUp();
    flag = false;

  }
  else if (distanceLower < 10 && flagObj) {
    //avoid
    LCD.writeonLCD("avoid");
    motion.avoid();
    motion.rightfesa();
    while (ir.getLeftReadings() == LOW && ir.getCenterReadings() == LOW && ir.getRightReadings() == LOW) {
      checkLine();
      motion.rightfesa();
    }
    motion.forward();
    delay(200);
    motion.left();
    delay(300);
    flagObj = false;
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
    LCD.writeonLCD("forward");
  }
  //W B B
  else if (left == LOW && center == HIGH && right == HIGH) {
    motion.right();
    //    Serial.println("Case Right");
    LCD.writeonLCD("right");

  }
  //B B W
  else if (left == HIGH && center == HIGH && right == LOW) {
    motion.left();
    //    Serial.println("Case left");
    LCD.writeonLCD("left");

  }
  //B B B
  else if (left == HIGH && center == HIGH && right == HIGH) {
    if (distanceLower < 10) {
      LCD.writeonLCD("Leave object");
      motion.Stop();
      delay(100);
      motion.backward();
      delay(700);
      motion.Stop();
      gripperUp.openGripperUp();
      gripperOpenClose.openGripper();
      motion.backward();
      delay(200);
      motion.Stop();
      delay(100000000);
    }
    else {
      motion.forward();
      //    Serial.println("Case Stop");
      LCD.writeonLCD("stop");
    }
  }
  //W W W
  else if (left == LOW && center == LOW && right == LOW) {
    motion.forward();
    //    Serial.println("Case Gap");
    LCD.writeonLCD("forward");

  }
  //make sure cases
  //W W B
  else if (left == LOW && center == LOW && right == HIGH) {
    motion.right();
    delay(50);
    //    Serial.println("Case hard right");
    LCD.writeonLCD("right");

  }
  //B W W
  else if (left == HIGH && center == LOW && right == LOW) {
    motion.left();
    delay(50);
    //    Serial.println("Case hard left");
    LCD.writeonLCD("left");

  }
  //B W B
  else if (left == HIGH && center == LOW && right == HIGH) {
    motion.forward();
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
