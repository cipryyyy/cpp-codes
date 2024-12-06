#include "../include/MazeLoader.h"

Maze::Maze(std::string path) {
    std::ifstream file(path);       //Creo un oggetto per leggere dal path

    if (!file.is_open()) {      //Se non si apre lancio l'eccezione
        throw Invalid();
    }

    for (int y = 0; y < DIM; y++) {     //Per ogni riga (coordinata y)
        std::string line;
        std::getline(file, line);           //Leggo la riga
        for (int x = 0; x < DIM; x++) {     //Per ogni caratter (coordinata x)
            MazeMatrix[x][y] = line[x];         //Salvo nella matrice
            if (line[x] == 'S') {               //S = punto di partenza
                MazeMatrix[x][y] = ' ';         //Rimpiazzo la S e diventa la posizione all'inizio
                currentPos[0] = x;
                currentPos[1] = y;
            }
            if (line[x] == 'E') {       //Punto d'arrivo
                end[0] = x;
                end[1] = y;
            }
        }
    }
    file.close();       //Chiudo il file
}

int* Maze::getPosition() noexcept{
    return currentPos;
}
int* Maze::getEnd() noexcept{
    return end;
}
int Maze::getDim() noexcept {
    return DIM;
}

//Controlli per vedere se tocco il muro
const bool Maze::isRightWall() const noexcept{
    return (MazeMatrix[currentPos[0]+1][currentPos[1]]=='*');
}
const bool Maze::isLeftWall() const noexcept{
    return (MazeMatrix[currentPos[0]-1][currentPos[1]]=='*');
}
const bool Maze::isTopWall() const noexcept{
    return (MazeMatrix[currentPos[0]][currentPos[1]-1]=='*');
}
const bool Maze::isBottomWall() const noexcept{
    return (MazeMatrix[currentPos[0]][currentPos[1]+1]=='*');
}


//Movimento e controllo che mi muovo solo di modulo 1 e in una sola direzione
void Maze::move(int x, int y) {
    if (((x > 1) || (x < -1)) || ((y > 1) || (y < -1)) || (x+y > 1)) {
        throw Maze::Invalid();
    }
    currentPos[0] += x;
    currentPos[1] -= y;
}

std::ostream& operator<< (std::ostream& os, const Maze& maze) {
    for (int y = 0; y < maze.DIM; y++) {
        for (int x = 0; x < maze.DIM; x++) {
            if (x == maze.currentPos[0] && y == maze.currentPos[1]) {   //Posizione attuale indicata con +
                os << "+";
            } else {
                os << maze.MazeMatrix[x][y];
            }
        }
        os << std::endl;
    }
    return os;
}