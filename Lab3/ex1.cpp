#include <iostream>
#include <time.h>
using namespace std;

void f() {
    int arr[10];
    int *pointer = arr;
    int *max = &arr[10];
    cout << pointer << endl;
    
    srand((unsigned)time(NULL));
    
    pointer += rand() % 10;
    
    for (int i = 0; i < 10; i++) {
        if (pointer >= max) {
            pointer = & arr[0];
        }
        *pointer = i;
        pointer++;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}

void f_illegal() {
    int arr[10];
    int *pointer = arr;
    cout << pointer << endl;
    
    srand((unsigned)time(NULL));
    
    pointer += rand() % 10;
    
    for (int i = 0; i < 10; i++) {
        *pointer = i;
        pointer++;
    }
    
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    f();
    cout << endl;
    f_illegal();
    
    return 0;
}
