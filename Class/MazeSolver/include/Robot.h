#ifndef Robot_h
#define Robot_h
#include "MazeLoader.h"

class Robot{
protected:
    Maze& maze;
    void moveUp() noexcept;
    void moveDown() noexcept;
    void moveRight() noexcept;
    void moveLeft() noexcept;

public:
    Robot(Maze& obj);

    int* getPosition() noexcept;
    virtual void move(char direction) noexcept;
};

class RandomRobot : public Robot {
    bool isDone() noexcept;
    std::vector<std::string> moves;
public:
    RandomRobot(Maze& obj) : Robot(obj) {}
    void move() noexcept;
    std::vector<std::string> getMoves() noexcept;
};

class RightHandRuleRobot : public Robot {
    char direction;
public:
    RightHandRuleRobot(Maze& obj) : Robot(obj) {
        direction = 'u';
    }
    void move() noexcept;
};

#endif