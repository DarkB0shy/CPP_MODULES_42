#include "../headers/ScalarConverter.hpp"

// A brief history of nan, +inf, -inf, nanf, +inff and -inff
// These are needed in order to implement the IEEE 754 standard for floating point arithmetic in modern computing. IEEE 754 was introduced to also handle exceptional cases in floating-point operations
// that involve concepts like infinity (inf) and not-a-number (NaN).
// +inf & -inf : dividing a positive/negative number by 0 will result in +/-inf. In c++98 these standards can be obtained through std::numeric_limits<double>::infinity() or
//                  std::numeric_limits<float>::infinity()
//                  These represent values that exceed the range of finite numbers.
//
// NaN : this represents a value that is undefined, such as 0 divided by 0 or the square root of a negative number. There are different kinds of nans, some of them throw exceptions.
//          Nan can be created through std::numeric_limits<float>::quiet_NaN() this applies for floating points.
// nanf, +inff, -inff : the 'f' in these "values" indicates they only apply to floating point operations. The <double> type has no suffix, so nan is just nan and so on.

ScalarConverter::ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
    if (literal.empty()) {
        std::cerr << "Error: Empty literal." << std::endl;
        return;
    }
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" ||
        literal == "nan" || literal == "+inf" || literal == "-inf") {
        handlePseudoLiterals(literal);
        return;
    }
    try {convertToChar(literal);}
    catch (const std::exception &e) {std::cerr << "char: impossible" << std::endl;}
    try {convertToInt(literal);}
    catch (const std::exception &e) {std::cerr << "int: impossible" << std::endl;}
    try {convertToFloat(literal);}
    catch (const std::exception &e) {std::cerr << "float: impossible" << std::endl;}
    try {convertToDouble(literal);}
    catch (const std::exception &e) {std::cerr << "double: impossible" << std::endl;}
}

void ScalarConverter::handlePseudoLiterals(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
    } else {
        std::cout << "float: " << literal + "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
}

void ScalarConverter::convertToChar(const std::string &literal) {
    if (literal.length() == 1 && isprint(literal[0])) {
        char charValue = literal[0];
        std::cout << "char: '" << charValue << "'" << std::endl;
    } else if (literal.length() == 1) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        throw std::exception();
    }
}

void ScalarConverter::convertToInt(const std::string &literal) {
    if (literal.length() == 1 && isdigit(literal[0])) {
        int intValue = literal[0] - '0';
        std::cout << "int: " << intValue << std::endl;
    } else if (literal.length() == 1) {
        int intValue = static_cast<int>(literal[0]);
        std::cout << "int: " << intValue << std::endl;
    } else {
        try {
            long long intValue = std::stoll(literal);
            if (intValue > std::numeric_limits<int>::max() || intValue < std::numeric_limits<int>::min()) {
                throw std::out_of_range("Value out of int range");
            }
            int intResult = static_cast<int>(intValue);
            std::cout << "int: " << intResult << std::endl;
        } catch (const std::invalid_argument& e) {
            throw std::exception();
        } catch (const std::out_of_range& e) {
            throw std::exception();
        }
    }
}

void ScalarConverter::convertToFloat(const std::string &literal) {
    float floatValue = static_cast<float>(std::atof(literal.c_str()));
    if (floatValue == 0.0f && literal != "0" && literal != "0.0") {throw std::exception();}
    std::cout << "float: " << std::fixed << std::setprecision(6) << floatValue << "f" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string &literal) {
    errno = 0;
    char* endPtr = nullptr;
    double doubleValue = static_cast<double>(std::strtod(literal.c_str(), &endPtr));
    if (errno != 0 || *endPtr != '\0') {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if (doubleValue == 0.0 && literal != "0" && literal != "0.0") {
        std::cout << "double: impossible" << std::endl;
        return;
    }
    std::cout << "double: " << std::fixed << std::setprecision(15) << doubleValue << std::endl;
}

// // void ScalarConverter::convertToInt(const std::string &literal) {                                                                             // static_cast can not be used to convert strings to numbers directly.
// //     errno = 0;                                                                                                                               // errno (#include <cerrno>) is a global variable used by functions such as strtol, strtod and strtof. It must be set to 0
// //     long intValue = std::strtol(literal.c_str(), NULL, 10);                                                                                  // so that those functions will work in a "clean" state. If errno is != 0 after the execution it means
// //     if (errno != 0 || intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max()) {throw std::exception();}    // the conversion went wrong.
// //     std::cout << "int: " << intValue << std::endl;
// // }

// // void ScalarConverter::convertToFloat(const std::string &literal) {
// //     errno = 0;
// //     float floatValue = std::strtof(literal.c_str(), NULL);
// //     if (errno != 0) {throw std::exception();}
// //     std::cout << "float: " << std::fixed << std::setprecision(7) << floatValue << "f" << std::endl;     // Floating-point variables usually have a precision of 7 decimals, but this can vary.
// // }                                                                                                       // They have a size of 4 bytes

// void ScalarConverter::convertToDouble(const std::string &literal) {
//     errno = 0;
//     double doubleValue = static_cast<double>(std::strtod(literal.c_str(), NULL));                                        // double variables have a precision of 15-16 decimals & have a size of 8 bytes
//     if (errno != 0) {throw std::exception();}                                                       // A "promotion cast" occurs when a smaller sized variable is
//     std::cout << "double: " << std::fixed << std::setprecision(15) << doubleValue << std::endl;     // implicitly casted to a bigger sized variable without losing data. 
// }                                                                                                   // This occurs when promoting a char (1 byte) to int (4 bytes): char c = 'a'; int i = c;
