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
void RandomRobot::setAttempt(int n) noexcept {
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

        bool b = maze.isBottomWall();
        bool t = maze.isTopWall();
        bool r = maze.isRightWall();
        bool l = maze.isLeftWall();
    
        if (b || t || r || l) {
            if (memory) {
                if (direction == 'r') {
                    if (b) {
                        if (r) {
                            direction = 'u';
                            Robot::moveUp();
                            memory = maze.isRightWall();
                        } else {
                            Robot::moveRight();
                        }
                    } else {
                        direction = 'd';
                        Robot::moveDown();
                        memory = maze.isLeftWall();
                    }
                }
                if (direction == 'd') {
                    if (l) {
                        if (b) {
                            direction = 'r';
                            Robot::moveRight();
                            memory = maze.isBottomWall();
                        } else {
                            Robot::moveDown();
                        }
                    } else {
                        direction = 'l';
                        Robot::moveLeft();
                        memory = maze.isTopWall();
                    }
                }
                if (direction == 'l') {
                    if (t) {
                        if (l) {
                            direction = 'd';
                            Robot::moveDown();
                            memory = maze.isLeftWall();
                        } else {
                            Robot::moveLeft();
                        }
                    } else {
                        direction = 'u';
                        Robot::moveUp();
                        memory = maze.isRightWall();
                    }
                }
                if (direction == 'u') {
                    if (r) {
                        if (t) {
                            direction = 'l';
                            Robot::moveLeft();
                            memory = maze.isTopWall();
                        } else {
                            Robot::moveUp();
                        }
                    } else {
                        direction = 'r';
                        Robot::moveRight();
                        memory = maze.isBottomWall();
                    }
                }
            } else {
                if (direction == 'r') {
                    if (r) {
                        Robot::moveUp();
                        direction = 'u';
                        memory = maze.isRightWall();
                    } else {
                        Robot::moveRight();
                        memory = maze.isBottomWall();
                    }
                }


                if (direction == 'd') {
                    if (b) {
                        Robot::moveRight();
                        direction = 'r';
                        memory = maze.isBottomWall();
                    } else {
                        Robot::moveDown();
                        memory = maze.isLeftWall();
                    }
                }


                if (direction == 'l') {
                    if (l) {
                        Robot::moveDown();
                        direction = 'd';
                        memory = maze.isLeftWall();
                    } else {
                        Robot::moveLeft();
                        memory = maze.isTopWall();
                    }
                }
                if (direction == 'u') {
                    if (t) {
                        Robot::moveLeft();
                        direction = 'l';
                        memory = maze.isTopWall();
                    } else {
                        Robot::moveUp();
                        memory = maze.isRightWall();
                    }
                }
            }
        } else {
            Robot::moveRight();         //Se sono nel mezzo, proseguo lungo destra
            memory = maze.isBottomWall();
        }
        if (maze.isBottomEnd()) {       //Se sono vicino alla fine, vado verso quelle coordinate
            Robot::moveDown();
            Robot::moves.push_back("SOLVED");
            return;
        }
        if (maze.isTopEnd()) {
            Robot::moveUp();
            Robot::moves.push_back("SOLVED");
            return;
        }
        if (maze.isRightEnd()) {
            Robot::moveRight();
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