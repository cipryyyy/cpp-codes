#ifndef Robot_h
#define Robot_h
#include "MazeLoader.h"
#include <iostream>

class Robot{
protected:
    std::vector<std::string> moves;
    Maze& maze;
    void moveUp() noexcept;
    void moveDown() noexcept;
    void moveRight() noexcept;
    void moveLeft() noexcept;

    bool isDone() noexcept;
public:
    Robot(Maze& obj);
    int* getPosition() noexcept;
    virtual void move(char direction) noexcept;
    std::vector<std::string> getMoves() noexcept;
};

class RandomRobot : public Robot {
private:
    int attempts = 256;
public:
    RandomRobot(Maze& obj) : Robot(obj) {}
    void move() noexcept;
    void setAttempt(int n) noexcept;
};

class RightHandRuleRobot : public Robot {
private:
    char direction = 'r';
    int attempts = 256;
public:
    RightHandRuleRobot(Maze& obj) : Robot(obj) {}
    void move() noexcept;
    void setAttempt(int n) noexcept;
};

#endif