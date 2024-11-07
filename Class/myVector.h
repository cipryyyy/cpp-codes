#ifndef Vector_h
#define Vector_h

constexpr int BUFFER = 256;

class Vector{
private:
    int s;
    int b;
    double *elem;

public:
    class Invalid{};
    
    Vector(int size = 0) : s{size}, b{BUFFER}, elem{new double[b]} {        //Costruttore standard
        if (s > b) {
            reserve(s);
        }
        if (s == 0) {
            elem = nullptr;
        }
        for (int i = 0; i < s; i++) {
            elem[i] = 0;
        }
    }
    //initlist
    Vector(std::initializer_list<double>lst) : s{static_cast<int>(lst.size())}, b{BUFFER}, elem{new double[b]} {
        std::copy(lst.begin(), lst.end(), elem);
    }
    //distruttore
    ~Vector() {
        delete[] elem;
    }
    //copy
    Vector& operator=(const Vector& copy) {
        if (this == &copy) {
            return *this;
        }
        
        delete[] elem;
        
        s = copy.s;
        b = copy.b;
        elem = new double[b];
        std::copy(copy.elem, copy.elem + s, elem);
        
        return *this;
    }
    Vector(const Vector& copy) : s{copy.s}, b{copy.b}, elem{new double[b]} {
        std::copy(copy.elem, copy.elem+s, elem);
    }
    
    //move
    
    Vector& operator=(Vector&& move) noexcept {
        if (this == &move) {
            return *this;
        }
        
        delete[] elem;
        
        s = move.s;
        b = move.b;
        elem = move.elem;
        
        move.s = 0;
        move.b = 0;
        move.elem = nullptr;
        
        return *this;
    }
    Vector(Vector&& move) noexcept : s{move.s}, b{move.b}, elem{move.elem} {
        move.s = 0;
        move.b = 0;
        move.elem = nullptr;
    }
    
    //override[]
    double& operator[](int index) {
        return elem[index];
    }
    const double& operator[](int index) const {
        return elem[index];
    }
    
    //override <<
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    
    //safeGet and safeSet
    void set(int index, double val) {
        if (index < 0 || index >= s) {
            throw Invalid();
        }
        elem[index] = val;
    }
    double get(int index) {
        if (index < 0 || index >= s) {
            throw Invalid();
        }
        return elem[index];
    }
    
    //reserve
    void reserve(int newBuffer) {
        if (newBuffer <= b) {
            return;
        }
        double *newElem = new double[newBuffer];
        
        std::copy(elem, elem+s, newElem);
        delete[] elem;
        
        elem = newElem;
        b = newBuffer;
    }
    
    //pushback and popback
    void pushback(double val) {
        if (s == b) {
            throw Invalid();
        }
        elem[s++] = val;
    }
    
    double popback() {
        if (s == 0) {
            throw Invalid();
        }
        return elem[s--];
    }
    
    //size
    int size() const {
        return s;
    }
    int buffer() const {
        return b;
    }
};

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (int i = 0; i < vec.s; i++) {
        os << vec.elem[i];
        if (i < vec.s-1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif /*Vector_h*/
