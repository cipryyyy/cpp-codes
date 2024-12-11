#ifndef Robot_h
#define Robot_h
#include "MazeLoader.h"

//Librerie per le animazioni
#include <thread>
#include <chrono> 
#include <cstdlib> 

class Robot{        //Robot a controllo manuale
protected:
    std::vector<std::string> moves;     //Elenco delle mosse fatte
    Maze& maze;                         //Labirinto in cui si trova il robot
    char direction;           //Direzione in cui guarda il robot
    void moveUp() noexcept;     //Movimento verso l'alto
    void moveDown() noexcept;   //Movimento verso il basso
    void moveRight() noexcept;  //Movimento verso destra
    void moveLeft() noexcept;   //Novimento verso sinistra

    bool isDone() noexcept;     //Controllo se sono arrivato alla fine
public:
    Robot(Maze& obj);
    int* getPosition() noexcept; 
    virtual void move(char direction) noexcept;     //Movimento generico
    std::vector<std::string> getMoves() noexcept;   //Elenco delle mosse
};

class RandomRobot : public Robot {      //Robot casuale
private:
    int attempts = 256;                 //Numero di tentativi prima del blocco
public:
    RandomRobot(Maze& obj) : Robot(obj) {}
    void move(bool animate = false, double timer = 0.25) noexcept;                   //Fa partire la risoluzione
    void setAttempt(int n) noexcept;
};

class RightHandRuleRobot : public Robot {       //Regola della mano destra
private:
    int attempts = 256;             //Tentativi disponibili
public:
    RightHandRuleRobot(Maze& obj) : Robot(obj) {
        if (maze.isLeftWall()) {
            direction = 'd';
        } else if (maze.isTopWall()) {
            direction = 'l';
        } else if (maze.isRightWall()) {
            direction = 'u';
        } else if (maze.isBottomWall()) {
            direction = 'r';
        } else {
            direction = 'r';
        }
    }
    void move(bool animate = false, double timer = 0.25) noexcept;                       //Risolutore
    void setAttempt(int n) noexcept;
};

#endif