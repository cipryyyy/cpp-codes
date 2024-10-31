#include <iostream>
using namespace std;

class myVector {
private:
    int sz;
    double *el;
public:
    myVector(int s) : sz(s), el(new double[s]){
        for (int i = 0; i < sz; i++) {
            el[i] = 0.0;
        }
    }

    int size() const {
        return sz;
    }
    
    double& operator[](int index) {
        return el[index];
    }
    const double& operator[](int index) const {
        return el[index];
    }
    
    void safe_set(int index, double value) {
        if (index < 0 || index >= sz){
            cout << "Index out of bound\n";
            return;
        }
        el[index] = value;
    }
    double safe_get(int index) {
        if (index < 0 || index >= sz){
            cout << "Index out of bound\n";
            return MAXFLOAT;
        }
        return el[index];
    }
    
    ~myVector() {
        delete[] el;;
    }
};
