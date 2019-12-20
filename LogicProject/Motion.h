#ifndef MOTION_H
#define MOTION_H
#define MR1 4
#define MR2 5
#define ML1 2
#define ML2 3

class Motion
{
  public:
    void forward();
    void backward();
    void right();
    void left();
    void Stop();
    void init();
    void avoid();
    void rightGripper();
    void leftGripper();
    void rightfesa();
    int Speed =80;
    int speedLeft = 80;
};
#endif // MOTION_H

