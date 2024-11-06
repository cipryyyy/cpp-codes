#ifndef Vector_h
#define Vector_h

template <typename T>
class Vector {
    int sz;
    int capacity;
    T* elem;

public:
    class Invalid{};
    
    Vector(std::initializer_list<T> lst)
        : sz{static_cast<int>(lst.size())}, capacity{static_cast<int>(lst.size())}, elem{new T[capacity]} {
        for (int i = 0; i < sz; ++i) {
            elem[i] = *(lst.begin() + i);
        }
    }
    
    explicit Vector(int size = 0)
        : sz{size}, capacity{size > 0 ? size : 1}, elem{new T[capacity]} {
        for (int i = 0; i < sz; i++) {
            elem[i] = T{};
        }
    }
    
    Vector(const Vector& vec)
        : sz{vec.sz}, capacity{vec.capacity}, elem{new T[capacity]} {
        for (int i = 0; i < sz; i++) {
            elem[i] = vec.elem[i];
        }
    }
    
    ~Vector() {
        delete[] elem;
    }
    
    Vector(Vector&& vec) noexcept : sz{vec.sz}, capacity{vec.capacity}, elem{vec.elem} {
        vec.sz = 0;
        vec.capacity = 0;
        vec.elem = nullptr;
    }
    
    Vector& operator=(Vector&& vec) noexcept {
        if (this != &vec) {
            delete[] elem;
            elem = vec.elem;
            sz = vec.sz;
            capacity = vec.capacity;
            vec.elem = nullptr;
            vec.sz = 0;
            vec.capacity = 0;
        }
        return *this;
    }
    
    T& operator[](int index) {
        if (index < 0 || index >= sz) {
            throw Invalid();
        }
        return elem[index];
    }
    
    const T& operator[](int index) const {
        if (index < 0 || index >= sz) {
            throw Invalid();
        }
        return elem[index];
    }
    
    T get(int index) const {
        if (index < 0 || index >= sz) {
            throw Invalid();
        }
        return elem[index];
    }
    
    void set(int index, T val = T{}) {
        if (index < 0 || index >= sz) {
            throw Invalid();
        }
        elem[index] = val;
    }
        
    int size() const {
        return sz;
    }
    
    int get_capacity() const {
        return capacity;
    }

    Vector& operator=(const Vector& vec) {
        if (this != &vec) {
            T* p = new T[vec.capacity];
            for (int i = 0; i < vec.sz; i++) {
                p[i] = vec.elem[i];
            }
            delete[] elem;
            elem = p;
            sz = vec.sz;
            capacity = vec.capacity;
        }
        return *this;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[";
        for (int i = 0; i < vec.sz; i++) {
            os << vec[i];
            if (i < vec.sz - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
    
    void pushback(const T& el) {
        if (sz == capacity) {
            capacity = capacity * 2;
            T* new_elem = new T[capacity];
            for (int i = 0; i < sz; i++) {
                new_elem[i] = elem[i];
            }
            delete[] elem;
            elem = new_elem;
        }
        elem[sz] = el;
        sz++;
    }
    
    std::string join(std::string inter) {
        std::string res;
        for (int i = 0; i < sz; i++) {
            res += elem[i];
            if (i < sz-1) {
                res += inter;
            }
        }
        return res;
    }
};

#endif /* Vector_h */
