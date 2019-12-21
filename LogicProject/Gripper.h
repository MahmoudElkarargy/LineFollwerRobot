#ifndef GRIPPER_H
#define GRIPPER_H


class Grip
{
  public:
    void init(int);
    int Signal ;
    void initUp(int);
    void openGripper();
    void closeGripper();
    void openGripperUp();
    void closeGripperUp();


};
#endif // GRIPPER_H

