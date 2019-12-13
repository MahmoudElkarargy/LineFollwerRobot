#ifndef IR_H
#define IR_H

#define SL 23
#define SR 27
#define SC 25


class Ir
{
  public:
    void init();
    void printReadings();
    int getLeftReadings();
    int getCenterReadings();
    int getRightReadings();
    int left;
    int right;
    int center;
};
#endif // IR_H

