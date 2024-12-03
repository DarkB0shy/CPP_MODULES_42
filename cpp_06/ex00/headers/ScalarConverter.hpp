#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstring>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>              // std::atoi, std::atof, ...
// #include <cerrno>
#include <limits>               // Range of values
#include <cmath>                // inf, nan, ...
#include <iomanip>              // std::fixed, std::setprecision

// A static class only contains static methods and no variables. There is also no need to create an object in order to use its functions.

class ScalarConverter {
    private:
        ScalarConverter();
        static void handlePseudoLiterals(const std::string &literal);
        static void convertToChar(const std::string &literal);
        static void convertToInt(const std::string &literal);
        static void convertToFloat(const std::string &literal);
        static void convertToDouble(const std::string &literal);
    public:
        static void convert(const std::string &literal);
};

void    checkInput(char * arg);

#endif