#include <iostream>
#include "../include/MazeLoader.h"
#include "../include/Robot.h"
using namespace std;

void printVector(std::vector<std::string> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size()-1) {
            cout << ", ";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        Maze maze(argv[1]);
        RightHandRuleRobot robot(maze);
        cout << maze;
        robot.move();
        cout << "Lista mosse:" << endl;
        printVector(robot.getMoves());
        cout << endl <<maze;
    } else {
        cout << "Inserire la directory con il file del labirinto" << endl << "./Maze path/to/maze";
    }
    return 0;
}