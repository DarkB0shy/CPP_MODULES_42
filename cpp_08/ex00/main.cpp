// STL stands for Standard Template Library and holds several kinds of containers. These differ from the "standard" arrays for a number of reasons, such as
// dynamic resizing, access patterns, ...
// std::list is implemented as a double linked list, so it does not have a fixed size. std::vector locates the elements in a contiguous block of memory unlike std::list.
// std::vector too resizes itself when elements are added or removed.
// Every container is fully compatible with STL algorithms like find, sort, etc.
// "Simple" arrays should only be used where the size of the list is fixed and memory usage is an issue; std::vector is usually a better replacement for them.
// Associative containers (mentioned in the subj) are part of the STL but they are designed to retrieve data faster thanks to their key-based research.

#include "headers/easyfind.hpp"

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 42};
    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Val found: " << *it << std::endl;
    } catch (const std::exception& e) {std::cout << e.what() << std::endl;}
    
    std::list<int> lst = {10, 20, 30, 40, 50};
    try {
        std::list<int>::iterator it = easyfind(lst, 21);
        std::cout << "Val found: " << *it << std::endl;
    } catch (const std::exception& e) {std::cout << e.what() << std::endl;}

    return (0);
}