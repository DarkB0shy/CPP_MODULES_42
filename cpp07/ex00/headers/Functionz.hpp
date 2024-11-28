#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

// Templates in c++ allow us to write generic classes & functions that are able to work with any data type. This comes with a number of advantages such as code
// reusability and more secure programming, as compiler checks the types at run time (preventing errors).
// Templates must be defined in the header files. These are function templates, there are class templates as well

#include <iostream>

template <typename T>                                  // Any data type is valid!
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T>
T max(const T& a, const T& b) {
    // return (a > b) ? a : b;
    if (a > b) return a; else return b;
}

#endif
