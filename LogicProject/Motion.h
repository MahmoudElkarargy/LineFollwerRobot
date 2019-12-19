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
    int Speed =50;
};
#endif // MOTION_H

