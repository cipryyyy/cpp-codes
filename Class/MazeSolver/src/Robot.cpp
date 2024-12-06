#include "../include/Robot.h"

//Protected functions

inline void Robot::moveUp() noexcept { //Se vado su
    if (maze.isTopWall()) {             //Controllo che non ci sia il muro
        return;
    }
    Robot::moves.push_back("Up");           //Log
    maze.move(0,1);                         //Mi muovo
}
inline void Robot::moveDown() noexcept {    //...
    if (maze.isBottomWall()) {
        return;
    }
    Robot::moves.push_back("Down");
    maze.move(0,-1);
}
inline void Robot::moveRight() noexcept {   //...
    if (maze.isRightWall()) {
        return;
    }
    Robot::moves.push_back("Right");
    maze.move(1,0);
}
inline void Robot::moveLeft() noexcept {    //...
    if (maze.isLeftWall()) {
        return;
    }
    Robot::moves.push_back("Left");
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
inline void RandomRobot::setAttempt(int n) noexcept {
    RandomRobot::attempts = n;
}

// RightHandRuleRobot Section
void RightHandRuleRobot::move() noexcept {
    std::srand(std::time(nullptr));
    bool loop = true;
    while (loop) {
        //Se ho finito o ho terminato i tentativi
        if (Robot::isDone() || Robot::moves.size() == RightHandRuleRobot::attempts) {
            loop = false;
            if (Robot::isDone()) {
                Robot::moves.push_back("SOLVED");
            }
            return;
        }

        //Se sono nel mezzo, proseguo lungo la direzione r
        if (!maze.isBottomWall() && !maze.isTopWall() && !maze.isLeftWall() && !maze.isRightWall()) {
            switch (direction) {
            case 'r':
                Robot::moveRight();
                break;
            case 'l':
                Robot::moveLeft();
                break;
            case 'u':
                Robot::moveUp();
                break;
            case 'd':
                Robot::moveDown();
                break;
            }
        }
        //Altrimenti, seguo il muro finché posso, poi giro
        else {
            if (direction == 'r') {
                if (maze.isRightWall()) {
                    direction = 'd';
                    Robot::moveDown();
                } else {
                    Robot::moveRight();
                }
            }
            else if (direction == 'd') {
                if (maze.isBottomWall()) {
                    direction = 'l';
                    Robot::moveLeft();
                } else {
                    Robot::moveDown();
                }
            }
            else if (direction == 'l') {
                if (maze.isLeftWall()) {
                    direction = 'u';
                    Robot::moveUp();
                } else {
                    Robot::moveLeft();
                }
            }
            else if (direction == 'u') {
                if (maze.isTopWall()) {
                    direction = 'r';
                    Robot::moveRight();
                } else {
                    Robot::moveUp();
                }
            }
        }
    }
}

inline void RightHandRuleRobot::setAttempt(int n) noexcept{
    RightHandRuleRobot::attempts = n;
}

