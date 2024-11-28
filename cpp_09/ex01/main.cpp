#include "headers/RPN.hpp"

//  "3 4 +"
//  "5 1 2 + 4 * + 3 -"
//  "1 2 3 4 5 6 7 8 9 10 11 +"
//  "3 4 + ( )"
//  "8 9 * 9 - 9 - 9 - 4 - 1 +"

int main (int argc, char *argv[]) {
    RPN rpn;
    if (argc != 2) std::cerr << "Need a reversed polish expression." << std::endl;
    else std::cout << rpn.parseExpression(argv[1]) << std::endl;
    return (0);
}
