template <typename T>
Array<T>::Array() : _array(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n + 1]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(nullptr), _size(0) {*this = other;}

template <typename T>
Array<T>::~Array() {delete[] _array;}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {_array[i] = other._array[i];}
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index > _size) {throw std::out_of_range(OUT_OF_BOUNDS);}
    return _array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {                       // Needed for non-modifiable objects of the given array, if there are any. This is a
    if (index > _size) {throw std::out_of_range(OUT_OF_BOUNDS);}               // common practice in c++ and kind of needed in a template class
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}
