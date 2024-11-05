//
//  Vector.h
//  free
//
//  Created by andre on 05/11/24.
//

#ifndef Vector_h
#define Vector_h

class myVector {
    
    int sz;         //Dimensione
    double *elem;   //puntatore
    
public:
    class Invalid{};     //Lancio di errori
    //Costruttore
    myVector(int size) : sz{size}, elem{new double[sz]}
    {
        for (int i = 0; i < sz; i++) {
            elem[i] = 0;                    //Assegnazione valori di default
        }
    }
    //Distruttore
    ~myVector() {
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
    
    friend std::ostream& operator<<(std::ostream& os, const myVector& vec);     //Overload ostream

    void pushback(const double& el) {       //Aggiunta di elementi
        elem[sz] = el;
        sz++;
    }
};

std::ostream& operator<<(std::ostream& os, const myVector& vec) {
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
