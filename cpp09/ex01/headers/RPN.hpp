#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <string>

class RPN {
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        double parseExpression(const std::string &expression);
        bool isOperator(char c) const;
        double performOperation(char op, double a, double b) const;
        void validateExpression(const std::string &expression) const;
};

#endif
