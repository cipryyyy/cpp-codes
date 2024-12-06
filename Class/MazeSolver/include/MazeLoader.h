#ifndef Maze_h
#define Maze_h
#include <fstream>
#include <cstdlib>

class Maze{
private:
    static constexpr int DIM = 9;
    int end[2];
    int currentPos[2];
    char MazeMatrix[DIM][DIM];
public:
    class Invalid {};

    Maze(std::string path);

    int* getPosition() noexcept;
    int* getEnd() noexcept;

    const bool isRightWall() const noexcept;
    const bool isLeftWall() const noexcept;
    const bool isTopWall() const noexcept;
    const bool isBottomWall() const noexcept;

    void move(int x, int y);

    friend std::ostream& operator<< (std::ostream& os, const Maze& maze);
};

#endif