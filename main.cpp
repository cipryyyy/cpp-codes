#include <iostream>
#include "Vector.h"
using namespace std;

constexpr int LEN = 20;     //Per ex 2

void f() {
    int arr[10];
    int *p = &arr[4];
    int *max = &arr[10];
    
    for (int i = 0; i < 10; i++) {
        if (p >= max) {
            p -= 10;
        }
        *p = i;
        p++;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << arr[i];
        if (i != 9) {
            cout << ", ";
        }
    }
}

void f_illegal() {
    int arr[10];
    int *p = &arr[4];
    
    for (int i = 0; i < 10; i++) {
        *p = i;
        p++;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << arr[i];
        if (i != 9) {
            cout << ", ";
        }
    }
}

void printReference(int& i, double& d) {
    cout << i << endl << d << endl;
}
void printPointer(int *i, double *d) {
    cout << *i << endl << *d << endl;
}

int printArrayLength(double arr[]) {
    return sizeof(arr);
    //Non conosce la dimensione dell'array
    //Posso accedere i dati perché arr è un puntatore al primo elemento
    //Non conosco le dimensioni, in questo caso però ho la COSTANTE LEN globale
}

int main() {
//  ex1
    f();                    //Tutto ok
    cout << endl;
//    f_illegal();          //Va in runtime exception, compila lo stesso
    cout << endl << endl;
    
//  ex2
    double arr[LEN];
    cout << sizeof(arr) << endl;    //160, LEN * 8
    cout << printArrayLength(arr) << endl << endl;
    
//  ex3
    int i = 12;
    double d = 3.1415;
    printReference(i, d);
    printPointer(&i, &d);
    
//  ex4
    myVector vec(5);
    vec.safeSet(2, 54.12);
    cout << vec;
}
