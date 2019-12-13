#include "Motion.h"
#include "IR.h"
#include "ultraSonic.h"


#define Signal1 10
#define Signal2 11
#define LCD1 26
#define LCD2 A0
#define LCD3 29
#define LCD4 31
#define LCD5 33
#define LCD6 35

int left;
int center;
int right;
int distanceLower;
int distanceUpper;

Motion motion;
Ir ir;
UltraSonic lowerUltraSonic;
UltraSonic upperUltraSonic;
void setup() {
  Serial.begin(9600);
  motion.init();
  ir.init();
  lowerUltraSonic.init(6, 7);
  upperUltraSonic.init(9, 8);
}

void loop() {
  //  motion.left();
  left = ir.getLeftReadings();
  center = ir.getCenterReadings();
  right = ir.getRightReadings();
  checkLine();
  //  ir.printReadings();

  distanceLower = lowerUltraSonic.returnDistance();
  distanceUpper = upperUltraSonic.returnDistance();
  
  Serial.print("Distance lower: ");
  Serial.println(distanceLower);

  Serial.print("Distance upper: ");
  Serial.println(distanceUpper);

//  if(distanceLower > 5 && distanceUpper > 5){
//    //avoid
//    motion.avoid();
//  }
//  else if(distanceLower > 5){
//    //catch
//    
//  }
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

