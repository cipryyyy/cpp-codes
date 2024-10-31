//
//  main.cpp
//  Rational
//
//

#include <iostream>
#include "Rational.h"
using namespace std;

int main() {
    Rational null;
    Rational a(5);
    Rational b(4, 7);
    
    cout << null << endl;
    cout << a << endl;
    cout << b << endl << endl;
    if (a==b) {
        cout << "Same" << endl;
    }
    if (a<b) {
        cout << a <<" smaller than " << b << endl << endl;
    }
    if (a>b) {
        cout << a << " greater than " << b << endl << endl;
    }
    
    Rational s = a+b;
    Rational p = a*b;
    Rational d = a/b;
    
    cout << s << endl << p << endl << d << endl << endl;
    
    int integer = 3;
    Rational test1 = a + integer;
    Rational test2 = integer + a;
    if (test1 == test2) {
        cout << "same" << endl;
    } else {
        cout << "different" << endl;
    }
    cout << test1 << endl << test2 << endl << endl;
    
    cout << a.toDouble() << endl << b.toDouble() << endl;
}
