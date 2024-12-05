#include "../include/Robot.h"

void Robot::moveUp() {
    maze.move(0,1);
}
void Robot::moveDown() {
    maze.move(0,-1);
}
void Robot::moveRight() {
    maze.move(1,0);
}
void Robot::moveLeft() {
    maze.move(-1,0);
}


Robot::Robot(const Maze& obj) : maze{obj}, direction{'u'} {}

inline int* Robot::getPosition() {
    return maze.getPosition();
}
bool Robot::isDone() {
    int* position = Robot::getPosition();
    int* end = Robot::maze.getEnd();

    return (position[0] == end[0] && position[1] == end[1]);
}

void Robot::move(char direction) {
    switch (direction)
    {
    case 'u':
        if (maze.isTopWall()) {
            return;
        }
        Robot::moveUp();
        break;
    case 'd':
        if (maze.isBottomWall()) {
            return;
        }
        Robot::moveDown();
        break;
    case 'r':
        if (maze.isRightWall()) {
            return;
        }
        Robot::moveRight();
        break;
    case 'l':
        if (maze.isLeftWall()) {
            return;
        }
        Robot::moveLeft();
        break;
    
    default:
        break;
    }
}

void RandomRobot::move() {
    
}
void RightHandRuleRobot::move() {

}