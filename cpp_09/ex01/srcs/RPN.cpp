#include "../headers/RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    // if (this != &other) {
    // }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {return (c == '+' || c == '-' || c == '*' || c == '/');}

double RPN::performOperation(char op, double a, double b) const {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Error: division by zero");
            return a / b;
        default: 
            throw std::runtime_error("Error: invalid operation");
    }
}

void RPN::validateExpression(const std::string &expression) const {
    int numCount = 0;
    for (size_t i = 0; i < expression.length(); ++i) {
        if (isdigit(expression[i])) {
            while (isdigit(expression[i])) i++;
        }
        else if (expression[i] != '+' && expression[i] != '-' &&
                   expression[i] != '*' && expression[i] != '/' &&
                   expression[i] != ' ') {
            std::cerr << "Error: invalid character in expression." << std::endl;
            exit(1);
        }
        numCount++;
    }
    if (numCount > 10) {
        std::cerr <<"Error: too many numbers in the expression." << std::endl;
        exit(1);
    }
}

double RPN::parseExpression(const std::string &expression) {
    validateExpression(expression);
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;
    while (iss >> token) {                                                          // This reads characters from iss into token.
        if (token.length() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) {
                std::cerr << "Error: invalid expression" << std::endl;
                exit(1);
            }
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            try {
                double result = performOperation(token[0], a, b);
                stack.push(result);
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
                exit(1);
            }
        } else {
            double number;
            std::istringstream numberStream(token);
            if (!(numberStream >> number)) {
                std::cerr << "Error: invalid number in expression" << std::endl;
                exit(1);
            }
            stack.push(number);
        }
    }
    if (stack.size() != 1) {
        std::cerr <<"Error: invalid expression" << std::endl;
        exit(1);
    }
    return stack.top();
}
