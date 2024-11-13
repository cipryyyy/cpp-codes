#ifndef vector_hpp
#define vector_hpp

template <typename T>
inline T& Vector<T>::operator[](int index) {
    if (index < 0 || index >= s) {
        throw Vector::OutOfBoundException();
    }
    return elem[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>& copy) noexcept{
    if (this == &copy) {
        return *this;
    }
    s = copy.s;
    b = copy.b;
    elem = new T[b];
    std::copy(copy.elem, copy.elem+s, elem);
    
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& move) noexcept{
    if (this == &move) {
        return *this;
    }
    s = move.s;
    b = move.b;
    elem = new T[b];
    std::copy(move.elem, move.elem+s, elem);
    
    move.s = 0;
    move.b = 0;
    move.elem = nullptr;
    
    return *this;
}

template <typename T>
inline void Vector<T>::pushback(T value) {
    if (s == b) {
        reserve(2*b);
    }
    if (elem == nullptr) {
        elem = new T[BUF];
    }
    elem[s++] = value;
}

template <typename T>
inline T Vector<T>::popback() {
    if (s == 0) {
        throw NullVectorException();
    }
    return elem[--s];
}

template <typename T>
void Vector<T>::reserve(int newBuffer) {
    if (newBuffer <= b) {
        return;
    }
    T *newElem = new T[newBuffer];
    std::copy(elem, elem+s, newElem);
    delete[] elem;
    elem = newElem;
    b = newBuffer;
}

template <typename T>
std::ostream& operator<<(std::ostream& os,const Vector<T>& vec) {
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

template <typename T>
void Vector<T>::insert(int index, T val) {
    if (index < 0 || index > s) {
        throw OutOfBoundException();
    }
    T *newElem = new T[++s];
    for (int i = 0; i < s; i++) {
        if (i < index) {
            newElem[i] = elem[i];
        }
        if (i == index) {
            newElem[i] = val;
        }
        if (i > index) {
            newElem[i] = elem[i-1];
        }
    }
    
    delete[] elem;
    elem = newElem;
}

template <typename T>
T Vector<T>::remove(int index) {
    if (index < 0 || index >= s) {
        throw OutOfBoundException();
    }

    T returnValue = elem[index];
    T *newElem = new T[--s];
    for (int i = 0; i < s; i++) {
        if (i < index) {
            newElem[i] = elem[i];
        } else {
            newElem[i] = elem[i + 1];
        }
    }

    delete[] elem;
    elem = newElem;
    return returnValue;
}

template <typename T>
void Vector<T>::clear() {
    s = 0;
    delete[] elem;
    elem = new T[b];
}

template <typename T>
void Vector<T>::resize(int newSize) {
    if (newSize <= s) {
        return;
    }
    if (newSize > b) {
        Vector::reserve(newSize);
    }
    s = newSize;
}

template <typename T>
T Vector<T>::begin() {
    return elem[0];
}

template <typename T>
T Vector<T>::end() {
    return elem[s-1];
}

template <typename T>
bool Vector<T>::contains(const T& search) {
    for (int i = 0; i < s; i++) {
        if (elem[i] == search) {
            return true;
        }
    }
    return false;
}

template <typename T>
int Vector<T>::indexOf(const T& search) {
    for (int i = 0; i < s; i++) {
        if (elem[i] == search) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void Vector<T>::reverse(){
    T *newElem = new T[s];
    for (int i = 0; i < s; i++) {
        newElem[i] = elem[s-i];
    }
    
    delete[] elem;
    elem = newElem;
}

template <typename T>
void Vector<T>::shrink() {
    T newElem = new T[s];
    std::copy(elem, elem+s, newElem);
    delete[] elem;
    elem = newElem;
    b = s;
}

#endif //vector_hpp
