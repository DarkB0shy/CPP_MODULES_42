#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#define OUT_OF_BOUNDS "Invalid index"

template <typename T>

class Array {
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();
        Array& operator=(const Array& other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};

#include "../srcs/Array.tpp"

// The ".tpp" include directive lets you have a special ".tpp" file where the compiler is gonna look into for the functions implementations. This can only be done
// when you have a class template. The main difference with a normal class is the way types and methods are handled. A template class is a generic class that works
// with any type; its type is defined by the compiler based on the specified type when an instance of the template is created.
// Also, the include must be after the class declaration otherwise the compiler will try to make sense of the ".tpp" file (template plus plus) before the class definition.

#endif
