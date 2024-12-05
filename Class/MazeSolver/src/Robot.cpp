#include "../include/Robot.h"

//Protected functions

inline void Robot::moveUp() noexcept {
    if (maze.isTopWall()) {
        return;
    }
    maze.move(0,1);
}
inline void Robot::moveDown() noexcept {
    if (maze.isBottomWall()) {
        return;
    }
    maze.move(0,-1);
}
inline void Robot::moveRight() noexcept {
    if (maze.isRightWall()) {
        return;
    }
    maze.move(1,0);
}
inline void Robot::moveLeft() noexcept {
    if (maze.isLeftWall()) {
        return;
    }
    maze.move(-1,0);
}

//Robot Section

Robot::Robot(Maze& obj) : maze{obj} {}

inline int* Robot::getPosition() noexcept {
    return maze.getPosition();
}

void Robot::move(char direction) noexcept {
    switch (direction)
    {
    case 'u':
        Robot::moveUp();
        break;
    case 'd':
        Robot::moveDown();
        break;
    case 'r':
        Robot::moveRight();
        break;
    case 'l':
        Robot::moveLeft();
        break;
    default:
        break;
    }
}

//RandomRobot Section

inline bool RandomRobot::isDone() noexcept {
    int* position = Robot::getPosition();
    int* end = Robot::maze.getEnd();

    return (position[0] == end[0] && position[1] == end[1]);
}

void RandomRobot::move() noexcept {
    std::srand(std::time(nullptr));
    bool loop = true;
    while (loop) {
        int choice = std::rand() % 4;

        switch (choice) {
        case 0:
            RandomRobot::moves.push_back("Up");
            Robot::moveUp();
            break;
        case 1:
            RandomRobot::moves.push_back("Down");
            Robot::moveDown();
            break;
        case 2:
            RandomRobot::moves.push_back("Right");
            Robot::moveRight();
            break;
        case 3:
            RandomRobot::moves.push_back("Left");
            Robot::moveLeft();
            break;
        }

        if (RandomRobot::isDone()) {
            loop = false;
        }
    }
}

inline std::vector<std::string> RandomRobot::getMoves() noexcept {
    return RandomRobot::moves;
}

// RightHandRuleRobot Section

void RightHandRuleRobot::move() noexcept {

}