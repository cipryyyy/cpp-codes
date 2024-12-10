#include "../include/Robot.h"
#include <iostream>

//Protected functions

inline void Robot::moveUp() noexcept { //Se vado su
    if (maze.isTopWall()) {             //Controllo che non ci sia il muro
        return;
    }
    Robot::moves.push_back("Up");           //Log
    direction = 'u';
    maze.move(0,1);                         //Mi muovo
}
inline void Robot::moveDown() noexcept {    //...
    if (maze.isBottomWall()) {
        return;
    }
    Robot::moves.push_back("Down");
    direction = 'd';
    maze.move(0,-1);
}
inline void Robot::moveRight() noexcept {   //...
    if (maze.isRightWall()) {
        return;
    }
    Robot::moves.push_back("Right");
    direction = 'r';
    maze.move(1,0);
}
inline void Robot::moveLeft() noexcept {    //...
    if (maze.isLeftWall()) {
        return;
    }
    Robot::moves.push_back("Left");
    direction = 'l';
    maze.move(-1,0);
}

inline bool Robot::isDone() noexcept {  
    int* position = Robot::getPosition();       //Posizione attuale
    int* end = Robot::maze.getEnd();            //Posizione d'arrivo

    return (position[0] == end[0] && position[1] == end[1]);        //Sono uguali?
}

//Robot Section

Robot::Robot(Maze& obj) : maze{obj} {}

inline int* Robot::getPosition() noexcept {
    return maze.getPosition();
}

void Robot::move(char direction) noexcept {
    switch (direction)                          //Comandi u, d, l, r
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

std::vector<std::string> Robot::getMoves() noexcept {
    return Robot::moves;
}

//RandomRobot Section

void RandomRobot::move() noexcept {
    std::srand(std::time(nullptr));     //Credo un seme casuale
    bool loop = true;

    while (loop) {
        int choice = std::rand() % 4;   //Genero un numero tra 0 e 3

        switch (choice) {               //Decido che movimento fare
        case 0:
            Robot::moveUp();
            break;
        case 1:
            Robot::moveDown();
            break;
        case 2:
            Robot::moveRight();
            break;
        case 3:
            Robot::moveLeft();
            break;
        }

        //Se ho finito o ho terminato i tentativi
        if (Robot::isDone() || Robot::moves.size() == RandomRobot::attempts) {
            loop = false;
            if (Robot::isDone()) {
                Robot::moves.push_back("SOLVED");       //Scrivo se lo ho risolto
            }
            return;
        }
    }
}
void RandomRobot::setAttempt(int n) noexcept {
    RandomRobot::attempts = n;
}

// RightHandRuleRobot Section
void RightHandRuleRobot::move() noexcept {
    int movesCounter = 0;
    while (movesCounter < attempts) {
        movesCounter++;
        switch (direction) {
            case 'r':
                if (maze.isBottomWall()) {
                    if (maze.isRightWall()){
                        Robot::moveUp();
                        Robot::direction = 'u';
                    } else {
                        Robot::moveRight();
                        Robot::moveDown();
                    }
                }
                break;
            case 'd':
                if (maze.isLeftWall()) {
                    if (maze.isBottomWall()){
                        Robot::moveRight();
                        Robot::direction = 'r';
                    } else {
                        Robot::moveDown();
                        Robot::moveLeft();
                    }
                }
                break;
            case 'l':
                if (maze.isTopWall()) {
                    if (maze.isLeftWall()){
                        Robot::moveDown();
                        Robot::direction = 'd';
                    } else {
                        Robot::moveLeft();
                        Robot::moveUp();
                    }
                }
                break;
            case 'u':
                if (maze.isRightWall()) {
                    if (maze.isTopWall()){
                        Robot::moveLeft();
                        Robot::direction = 'l';
                    } else {
                        Robot::moveUp();
                        Robot::moveRight();
                    }
                }
                break;
        }
        if (maze.isBottomEnd()) {
            Robot::moveDown();
            Robot::moves.push_back("SOLVED");
            return;
        }
        if (maze.isRightEnd()) {
            Robot::moveRight();
            Robot::moves.push_back("SOLVED");
            return;
        }
        if (maze.isTopEnd()) {
            Robot::moveUp();
            Robot::moves.push_back("SOLVED");
            return;
        }
        if (maze.isLeftEnd()) {
            Robot::moveLeft();
            Robot::moves.push_back("SOLVED");
            return;
        }
    }
}
void RightHandRuleRobot::setAttempt(int n) noexcept{
    RightHandRuleRobot::attempts = n;
}