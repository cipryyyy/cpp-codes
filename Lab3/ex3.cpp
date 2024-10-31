#include <iostream>

using namespace std;

void printReference(int &e){
    cout << e << endl;
}
void printReference(double &e){
    cout << e << endl;
}

void printPointer(int *e){
    cout << *e << endl;
}
void printPointer(double *e){
    cout << *e << endl;
}

int ex3() {
    int i = 1;
    double d = 1.43;
    int *pi = &i;
    double *pd = &d;
    
    printReference(i);
    printReference(d);
    
    printPointer(pi);
    printPointer(pd);
    
    return 0;
}
