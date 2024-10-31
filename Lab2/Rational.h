//
//  Rational.h
//  Rational
//
//

#ifndef Rational_h
#define Rational_h

class Rational {
private:
    int num;
    int den;
public:
    Rational() {
        num = 0;
        den = 1;
    }
    Rational(int n) {
        num = n;
        den = 1;
    }
    Rational(int n, int d) {
        num = n;
        den = d;
    }
    
    int getNum() {
        return num;
    }
    int getDen() {
        return den;
    }
    
    double toDouble() {
        return ((1.0)*num) / ((1.0)*den);
    }

    friend std::ostream& operator<< (std::ostream& os, Rational r);
    friend bool operator== (Rational l, Rational r);
    friend bool operator< (Rational l, Rational r);
    friend bool operator> (Rational l, Rational r);
    friend Rational operator+ (Rational l, Rational r);
    friend Rational operator+ (Rational l, int a);      //Override
    friend Rational operator- (Rational l, Rational r);
    friend Rational operator* (Rational l, Rational r);
    friend Rational operator/ (Rational l, Rational r);
};

//output stream
std::ostream& operator<< (std::ostream& os, Rational r){
    if (r.getDen() == 1) {
        return os << r.getNum();
    }
    return os << r.getNum() << "/" << r.getDen();
}

//logic operations
bool operator== (Rational l, Rational r) {
    return l.getNum() * r.getDen() == r.getNum() * l.getDen();
}

bool operator< (Rational l, Rational r) {
    return l.getNum() * r.getDen() < r.getNum() * l.getDen();
}
bool operator> (Rational l, Rational r) {
    return l.getNum() * r.getDen() > r.getNum() * l.getDen();
}

//arithmetic operation
Rational operator+ (Rational l, Rational r) {
    int common = l.getDen() * r.getDen();
    return Rational(l.getNum() * (r.getDen()) + r.getNum() * (l.getDen()), common);
}
Rational operator+ (Rational l, int a) {                //override
    return Rational(l.getNum() + a * l.getDen(), l.getDen());
}
Rational operator- (Rational l, Rational r) {
    int common = l.getDen() * r.getDen();
    return Rational(l.getNum() * (r.getDen()) - r.getNum() * (l.getDen()), common);
}
Rational operator* (Rational l, Rational r) {
    return Rational(l.getNum() * r.getNum(), l.getDen() * r.getDen());
}
Rational operator/ (Rational l, Rational r) {
    return Rational(l.getDen() * r.getNum(), l.getNum() * r.getDen());
}

#endif /* Rational_h */
