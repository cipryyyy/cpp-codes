#ifndef Robot_h
#define Robot_h
#include "MazeLoader.h"

class Robot{        //Robot a controllo manuale
protected:
    std::vector<std::string> moves;     //Elenco delle mosse fatte
    Maze& maze;                         //Labirinto in cui si trova il robot
    void moveUp() noexcept;     //Movimenti specifici, con controlli
    void moveDown() noexcept;
    void moveRight() noexcept;
    void moveLeft() noexcept;

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
    void move() noexcept;                   //Fa partire la risoluzione
    void setAttempt(int n) noexcept;
};

class RightHandRuleRobot : public Robot {       //Regola della mano destra
private:
    char direction = 'r';           //Direzione in cui guarda il robot
    int attempts = 256;             //Tentativi disponibili
public:
    RightHandRuleRobot(Maze& obj) : Robot(obj) {}
    void move() noexcept;                       //Risolutore
    void setAttempt(int n) noexcept;
};

#endif