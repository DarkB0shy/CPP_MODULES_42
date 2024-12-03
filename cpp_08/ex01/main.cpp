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

        std::vector<int> vec = {6, 7, 19};
        sp.addNumbers(vec.begin(), vec.end());
        sp.printElements();
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {std::cerr << "Exception: " << e.what() << std::endl;}

    return (0);
}
