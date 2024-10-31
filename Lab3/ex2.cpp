#include <iostream>
using namespace std;

constexpr int LEN = 8;

void printArrayLength(double arr[]) {
    cout << sizeof(arr) << endl;
}

int ex2() {
    double arr[LEN];
    double *pointer = arr;
    cout << sizeof(arr) << endl;
    printArrayLength(arr);
}
