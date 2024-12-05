#ifndef Robot_h
#define Robot_h
#include "MazeLoader.h"

class Robot{
private:
    Maze maze;
    char direction;

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
public:
    Robot(const Maze& obj);

    int* getPosition();
    bool isDone();
    virtual void move(char direction);
};

class RandomRobot : public Robot {
    void move();
};

class RightHandRuleRobot : public Robot {
    void move();
};

#endif