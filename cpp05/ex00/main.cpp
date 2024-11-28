#include "headers/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        } catch (std::exception &e) {std::cerr<<"Exception: "<<e.what()<<std::endl;}
    try {
        std::cout << std::endl;
        Bureaucrat rando;
        std::cout << rando << std::endl;
        rando.decrementGrade();
        std::cout << rando << std::endl;
        rando.decrementGrade();
        std::cout << rando << std::endl;
        } catch (std::exception &e) {std::cerr<<"Exception: "<<e.what()<<std::endl;}
    return (0);
}
