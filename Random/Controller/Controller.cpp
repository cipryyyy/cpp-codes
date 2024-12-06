#include <iostream>
#include <ncurses.h>
#include <thread>
#include <atomic>
#include "MazeLoader.h"
#include "Robot.h"
using namespace std;

void checkKeys(std::atomic<bool>& running, Maze& maze, Robot& RC) {
    while (running) {
        int ch = wgetch(stdscr); // Leggi il carattere premuto
        if (ch != ERR) {
            clear(); // Pulisci lo schermo
            switch (ch) {
                case KEY_UP:
                    RC.moveUp();
                    printw("Arrow Up pressed\n");
                    break;
                case KEY_DOWN:
                    RC.moveDown();
                    printw("Arrow Down pressed\n");
                    break;
                case KEY_LEFT:
                    RC.moveLeft();
                    printw("Arrow Left pressed\n");
                    break;
                case KEY_RIGHT:
                    RC.moveRight();
                    printw("Arrow Right pressed\n");
                    break;
                default:
                    printw("Unknown key pressed\n");
                    break;
            }
            
            // Usa printw per stampare il labirinto
            
            // Stampa il labirinto usando printw invece di std::cout
            for (int y = 0; y < maze.DIM; y++) {
                for (int x = 0; x < maze.DIM; x++) {
                    if (x == maze.currentPos[0] && y == maze.currentPos[1]) {
                        printw("+"); // Posizione attuale
                    } else {
                        printw("%c", maze.MazeMatrix[x][y]);
                    }
                }
                printw("\n");
            }
            if (RC.isDone()) {
                printw("Vinto");
                running = false;
            }
            refresh(); // Aggiorna il display
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(120)); // Ritardo per evitare uso eccessivo della CPU
    }
}

int main() {
    initscr();
    keypad(stdscr, TRUE);    // Abilita la lettura delle frecce
    nodelay(stdscr, TRUE);   // Non bloccare il programma sulla lettura dell'input
    noecho();                // Non visualizzare i tasti premuti

    std::atomic<bool> running(true);

    // Crea il labirinto e il robot
    Maze maze("/Users/macbook/Documents/Github/cpp-codes/Class/MazeSolver/src/mazes/maze4.txt");
    Robot RCR(maze);
    printw("Usa i tasti freccia per muoverti.\n");
    for (int y = 0; y < maze.DIM; y++) {
        for (int x = 0; x < maze.DIM; x++) {
            if (x == maze.currentPos[0] && y == maze.currentPos[1]) {
                printw("+"); // Posizione attuale
            } else {
                printw("%c", maze.MazeMatrix[x][y]);
            }
        }
        printw("\n");
    }

    // Crea un thread per leggere i tasti
    std::thread inputThread(checkKeys, std::ref(running), std::ref(maze), std::ref(RCR));

    // Simula il programma principale che può fare altre operazioni (ad esempio, il robot si muove)
    std::this_thread::sleep_for(std::chrono::seconds(60));  // Esegui il programma per un po'

    // Ferma il thread di lettura dell'input
    running = false;
    inputThread.join(); // Aspetta che il thread finisca

    endwin(); // Chiudi ncurses
    return 0;
}
