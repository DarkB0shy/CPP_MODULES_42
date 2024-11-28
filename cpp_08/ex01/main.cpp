#include "headers/Span.hpp"

int main() {
    try {
        Span sp(5000);
        sp.addNumber(11);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.printElements();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        int arr[] = {6, 7, 19};
        sp.addNumbers(arr, arr + 3);                                                            // In c++98 arrays can decay to pointers and can be used as iterators.
        sp.printElements();                                                                     // This happens because arr is treated as a pointer of type int* to its first element.
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;                       // It is the same as writing &arr[0]. In c++, pointers can act as iterators but
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;                         // not all iterators are pointers for they can do "more things" than a regular pointer.
    } catch (const std::exception &e) {std::cerr << "Exception: " << e.what() << std::endl;}

    return (0);
}
