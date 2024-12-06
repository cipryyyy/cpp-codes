#ifndef Maze_h
#define Maze_h
#include <fstream>      //Stream per la lettura file

class Maze{
private:
    static constexpr int DIM = 9;       //Dimensione del labirinto
    int end[2];                         //Punto d'arrivo
    int currentPos[2];                  //Posizione attuale
    char MazeMatrix[DIM][DIM];          //Matrice con i dati del labirinto
public:
    class Invalid {};

    Maze(std::string path);

    int* getPosition() noexcept;
    int* getEnd() noexcept;
    int getDim() noexcept;

    const bool isRightWall() const noexcept;
    const bool isLeftWall() const noexcept;
    const bool isTopWall() const noexcept;
    const bool isBottomWall() const noexcept;


    void move(int x, int y);                //Sposta la posizione corrente

    friend std::ostream& operator<< (std::ostream& os, const Maze& maze);   //Stampa il labirinto
};

#endif