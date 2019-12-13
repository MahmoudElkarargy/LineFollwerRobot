#ifndef ULTRASONIC_H
#define ULTRASONIC_H


class UltraSonic
{
  public:
    int echo;
    int trig;
    long duration;
    int distance;
    void init(int, int);
    int returnDistance();
};
#endif // ULTRASONIC_H

