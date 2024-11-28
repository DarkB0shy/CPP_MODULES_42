#include <iostream>
#include "headers/Iter.hpp"

// struct PrintElement {                               // This is a functor: a struct or a class that overloads the operator() function. This allows its instances to be
//     template <typename T>                           // used as if they were functions. It is useful in this scope because it can be passed to the iter f template
//     void operator()(const T& element) const {       // without having to manually cast the type of the function in the main() to avoid compilation errors.
//         std::cout << element << " ";                // There are other ways to achieve the same result. Like an instance of a function template.
//     }
// };

template <typename T>
void printElement(T& element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "Array of integers: ";
    iter(intArray, intArrayLength, printElement);                               // Adding the () to printElement will get the compiler to try and execute the method
    std::cout << std::endl;                                                     // instead of treating it as a function pointer.
    std::string stringArray[] = {"Grey", "Boshy", "the 3rd"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);
    std::cout << "Array of strings: ";
    iter(stringArray, stringArrayLength, printElement);
    std::cout << std::endl;

    return (0);
}
