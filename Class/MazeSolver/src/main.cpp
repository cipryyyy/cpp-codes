#include <iostream>
#include "../include/MazeLoader.h"
#include "../include/Robot.h"
using namespace std;

void printVector(std::vector<std::string> vec) {    //Funzione per stampare le mosse
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size()-1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {                     //Controllo il numero di argomenti della chiamata
        Maze mazeRHRR(argv[1]);                 //Creo un oggetto Maze per il primo robot
        Maze mazeRNDR(argv[1]);                 //Creo un oggetto Maze per il secondo
        RightHandRuleRobot robotRHRR(mazeRHRR);     //Creo un oggetto Robot con regola della mano destra
        RandomRobot robotRNDM(mazeRNDR);     //Creo un oggetto Robot con movimenti casuali

        cout << mazeRHRR;

        robotRHRR.move();   //Faccio partire i robot  
        robotRNDM.move(); 

        //Risultati
        cout << "Lista mosse con regola della mano destra:" << endl;
        printVector(robotRHRR.getMoves());
        cout << "Lista mosse con movimenti casuali:" << endl;
        printVector(robotRNDM.getMoves());

    } else {
        cout << "Inserire la directory con il file del labirinto" << endl << "./Maze path/to/maze";
    }
    return 0;
}