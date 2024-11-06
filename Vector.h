#ifndef Vector_h
#define Vector_h

class myVector {
private:
    int sz;
    double *elem;
    
public:
    class Invalid {};

    explicit myVector (int s) : sz{s}, elem{new double[s]}
    {
        for (int i = 0; i < sz; i++) {
            elem[i] = 0;
        }
    }
    ~myVector() {
        delete[] elem;
    }
    
    double& operator[] (int index) {
        return elem[index];
    }
    const double& operator[] (int index) const {
        return elem[index];
    }
    
    void safeSet(int index, double value) {
        if (index < 0 || index >= sz) {
            throw Invalid();
        }
        elem[index] = value;
    }
    double safeGet(int index) {
        if (index < 0 || index >= sz) {
            throw Invalid();
        }
        return elem[index];
    }
    
    friend std::ostream& operator<<(std::ostream& os, const myVector& vec);
    
};


std::ostream& operator<<(std::ostream& os, const myVector& vec) {
    os << "[";
    for (int i = 0; i < vec.sz; i++) {
        os << vec.elem[i];
        if (i < vec.sz-1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif /* Vector_h */
