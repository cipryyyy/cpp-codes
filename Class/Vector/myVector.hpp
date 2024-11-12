#ifndef myVector_hpp
#define myVector_hpp

template <typename T>
T& Vector<T>::operator[](int index) {
    if (index < 0 || index > s) {
        throw Invalid();
    }
    return elem[index];
}

template <typename T>
T& Vector<T>::operator=(Vector<T>& copy) {
    if (this == &copy) {
        return *this;
    }
    delete[] elem;
    s = copy.s;
    b = copy.b;
    elem = copy.elem;
    return *this;
}

template <typename T>
T& Vector<T>::operator=(Vector<T>&& move) {
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

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << "[";
    for (int i = 0; i<vec.s; i++) {
        os << vec.elem[i];
        if (i < vec.s-1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

template <typename T>
void Vector<T>::pushback(T value) {
    if (b==s) {
        Vector::reserve(2*b);
    }
    elem[s++] = value;
}

template <typename T>
T& Vector<T>::popback() {
    if (b==0) {
        throw Vector<T>::Invalid();
    }
    return elem[--s];
}

template <typename T>
void Vector<T>::reserve(int Newbuffer) {
    if (Newbuffer <= b) {
        return;
    }
    T *newElem = new T[Newbuffer];
    std::copy(elem, elem + s, newElem);
    delete[] elem;
    elem = newElem;
    b = Newbuffer;
}
#endif /*myVector_hpp*/
