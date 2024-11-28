#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>

#define VAL_NOT_FOUND "Val not found inside the container."

// An iterator iterates between all the elements of the container, it can also perform operations on its elements. It is a pointer-like variable.

template <typename T>
typename T::iterator easyfind(T& container, int value) {                                // This represents an iterator for the <type T> container. Its behaviour changes
    typename T::iterator it = std::find(container.begin(), container.end(), value);     // among different containers. For example, std::vector has a random-access iterator,
    if (it == container.end()) {                                                        // std::list has a bidirectional one meaning you can move "back and forth".
        throw std::runtime_error(VAL_NOT_FOUND);                                        // An iterator is a pointer-like object that allows to iteratate over the elements of a container.
    }                                                                                   // The "typename" keyword is needed in order to be able to work with different containers and templates.
    return (it);                                                                        // If the iterator holds the value container.end() it means the value has not been found.
}