#include "../include/MazeLoader.h"

Maze::Maze(std::string path) {
    std::ifstream file(path);
    for (int y = 0; y < DIM; y++) {
        std::string line;
        std::getline(file, line);
        for (int x = 0; x < DIM; x++) {
            MazeMatrix[y][x] = line[x];
            if (line[x] == 'S') {
                currentPos[0] = x;
                currentPos[1] = y;
            }
            if (line[x] == 'E') {
                end[0] = x;
                end[1] = y;
            }
        }
    }
    file.close();
}

int* Maze::getPosition() noexcept{
    return currentPos;
}
int* Maze::getEnd() noexcept{
    return end;
}

const bool Maze::isRightWall() const noexcept{
    return (MazeMatrix[currentPos[0]][currentPos[1]+1]=='*');
}
const bool Maze::isLeftWall() const noexcept{
    return (MazeMatrix[currentPos[0]][currentPos[1]-1]=='*');
}
const bool Maze::isTopWall() const noexcept{
    return (MazeMatrix[currentPos[0]+1][currentPos[1]]=='*');
}
const bool Maze::isBottomWall() const noexcept{
    return (MazeMatrix[currentPos[0]-1][currentPos[1]]=='*');
}

void Maze::move(int x, int y) {
    if ((std::abs(x) > 1) || (std::abs(y) > 1) || (x+y > 1)) {
        throw Maze::Invalid();
    }
    currentPos[0] += x;
    currentPos[1] += y;
}

std::ostream& operator<< (std::ostream& os, const Maze& maze) {
    for (int i = 0; i < maze.DIM; i++) {
        for (int j = 0; j < maze.DIM; j++) {
            os << maze.MazeMatrix[i][j];
        }
        os << std::endl;
    }
    return os;
}