#include <iostream>
#include "../include/MazeLoader.h"
#include "../include/Robot.h"
using namespace std;

int main() {
    Maze maze("/Users/macbook/Documents/Github/cpp-codes/Class/MazeSolver/src/mazes/maze1.txt");
    RandomRobot robot(maze);
    cout << maze;
    robot.move();
    cout << maze;

    return 0;
}