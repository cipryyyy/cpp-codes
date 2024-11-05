//
//  Vector.h
//
//  Created by andre on 05/11/24.
//

#ifndef Vector_h
#define Vector_h

class Vector {
    
    int sz;         //Dimensione
    double *elem;   //puntatore
    
public:
    class Invalid{};     //Lancio di errori
    //Costruttore con elementi
    Vector(std::initializer_list<double>lst) : sz{static_cast<int>(lst.size())}, elem{new double[sz]} {
        std::copy(lst.begin(), lst.end(), elem);
    }
    //costruttore vuoto
    Vector(int size = 0) : sz{size}, elem{new double[sz]}
    {
        if (sz == 0) {
            elem = nullptr;
        }
        for (int i = 0; i < sz; i++) {
            elem[i] = 0;                    //Assegnazione valori di default
        }
    }
    //Costruttore di copia
    Vector(const Vector& vec) : sz{vec.size()}, elem{new double[sz]}
    {
        std::copy(vec.elem, vec.elem+sz, elem);
    }
    //Distruttore
    ~Vector() {
        delete[] elem;
    }
        
    double& operator[](int index) {     //Passaggio a riferimento, consente lettura e scrittura
        if (index < 0 || index >= sz) {     //Errori nell'utilizzo
            throw Invalid();
        }
        return elem[index];
    }
    const double& operator[](int index) const { //Versione const
        if (index < 0 || index >= sz) {
            throw Invalid();
        }
        return elem[index];
    }
        
    int size() const{       //Ritorna la dimensione
        return sz;
    }
    
    //override =
    Vector& operator= (const Vector& vec);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);     //Overload ostream

    void pushback(const double& el) {       //Aggiunta di elementi
        if (sz == 0) {
            elem = new double[1];
        }
        elem[sz] = el;
        sz++;
    }
};

Vector& Vector::operator= (const Vector& vec) {
    double *p = new double[vec.size()];
    std::copy(vec.elem, vec.elem+sz, p);
    delete[] elem;
    elem = p;
    sz = vec.sz;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    os << "[";
    for (int i = 0; i < vec.sz; i++) {
        os << vec[i];
        if (i < vec.size()-1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif /* Vector_h */
