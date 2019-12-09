#include "Motion.h"
#include "IR.h"

#define echo1 6
#define echo2 9
#define trig1 7
#define trig2 8
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

Motion motion;  
Ir ir;
void setup() {
  Serial.begin(9600);
  motion.init();
  ir.init();
}

void loop() {
//  motion.forward();
//left = ir.getLeftReadings();
//center = ir.getCenterReadings();
//right = ir.getRightReadings();
//  checkLine();
  
}





void checkLine(){
  //HIGH --> White
  // W B W
  if(left == HIGH && center == LOW && right == HIGH){
     motion.forward();
     Serial.println("Case Forward");
  }
  //W B B
  else if(left == HIGH && center == LOW && right == LOW){
     motion.right();
     Serial.println("Case Right");
  }
  //B B W
  else if(left == LOW && center == LOW && right == HIGH){
     motion.left();
     Serial.println("Case left");
  }
  //B B B
  else if(left == LOW && center == LOW && right == LOW){
     motion.Stop();
     Serial.println("Case Stop");
  }
  //W W W
  else if(left == HIGH && center == HIGH && right == HIGH){
     motion.forward();
     Serial.println("Case Gap");
  }
  //make sure cases
  //W W B
  else if(left == HIGH && center == HIGH && right == LOW){
     motion.right();
     Serial.println("Case hard right");
  }
  //B W W
  else if(left == LOW && center == HIGH && right == HIGH){
     motion.left();
     Serial.println("Case hard left");
  }
  //B W B
  else if(left == HIGH && center == HIGH && right == LOW){
     motion.Stop();
     Serial.println("WTF?");
  }
}

