#ifndef myVector_h
#define myVector_h

constexpr int DEF = 1024;
template <typename T>

class Vector {
    int s;
    int b;
    T *elem;
public:
    class Invalid{};
    Vector(int size = 0) : s{size}, b{(size<DEF)? DEF : s}, elem{new T[b]} {
        for (int i = 0; i < s; i++) {
            elem[i] = T();
        }
    }
    Vector(std::initializer_list<T> lst) : s{static_cast<int>(lst.size())}, b{(static_cast<int>(lst.size())<DEF)? DEF : static_cast<int>(lst.size())}, elem{new T[b]} {
        std::copy(lst.begin(), lst.end(), elem);
    }
    Vector(Vector<T>& copy) : s{copy.s}, b{copy.b}, elem{new T[b]} {
        std::copy(copy.elem, copy.elem+s, elem);
    }
    Vector(Vector<T>&& move) : s{move.s}, b{move.b}, elem{new T[b]} {
        std::copy(move.elem, move.elem+s, elem);
        move.s = 0;
        move.b = 0;
        move.elem = nullptr;
    }
    ~Vector() {
        delete[] elem;
    }
    
    T& operator[](int index);
    T& operator=(Vector<T>& copy);
    T& operator=(Vector<T>&& move);
    void pushback(T value);
    T& popback();
    void reserve(int Newbuffer);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& vec);
    
    int size() const {
        return s;
    }
    int buffer() const {
        return b;
    }
};

#include "myVector.hpp"

#endif //template_h
