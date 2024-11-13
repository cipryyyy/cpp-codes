#ifndef vector_h
#define vector_h

constexpr int BUF = 1024;

template <typename T>
class Vector {
    int s;
    int b;
    T *elem;
public:
    struct OutOfBoundException : public std::exception {
        const char* what() const noexcept override {
            return "Index out of bounds!";
        }
    };
    struct NullVectorException : public std::exception {
        const char* what() const noexcept override {
            return "Size 0, cannot decrement!";
        }
    };
    
    explicit Vector(int size = 0) : s{size}, b{(size>BUF)? size : BUF}, elem{(size==0)? nullptr : new T[BUF]} {
        for (int i = 0; i < s; i++) {
            elem[i] = T();
        }
    }
    Vector(std::initializer_list<T> lst) : s{static_cast<int>(lst.size())}, b{(static_cast<int>(lst.size())>BUF) ? static_cast<int>(lst.size()) : BUF}, elem{new T[static_cast<int>(lst.size())]} {
        for (int i = 0; i < s; i++) {
            std::copy(lst.begin(), lst.end(), elem);
        }
    }
    Vector<T>(Vector<T>& copy) : s{copy.s}, b{copy.b}, elem{new T[b]} {
        std::copy(copy.elem, copy.elem + s, elem);
    }
    Vector<T>(Vector<T>&& move) : s{move.s}, b{move.b}, elem{new T[b]} {
        std::copy(move.elem, move.elem + s, elem);
        
        move.s = 0;
        move.b = 0;
        move.elem = nullptr;
    }
    ~Vector() {
        delete[] elem;
    }
    
    int size() const {
        return s;
    }
    int buffer() const {
        return b;
    }
    
    virtual T& operator[](int index);
    Vector& operator=(Vector<T>& copy) noexcept;
    Vector& operator=(Vector<T>&& move) noexcept;
    virtual void pushback(T value);
    virtual T popback();
    void reserve(int newBuffer);
    void insert(int index, T val);
    T remove(int index);
    void clear();
    void resize(int newSize);
    T begin();
    T end();
    bool contains(const T& search);
    int indexOf(const T& search);
    void reverse();
    void shrink();
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os,const Vector<U>& vec);
};

#include "vector.hpp"

#endif //vector_h
