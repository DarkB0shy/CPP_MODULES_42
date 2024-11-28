// When defining exceptions in c++98, the following keywords are needed:
// virtual  :   this function can be overridden by derived classes
// const char * :   this function will return a const char *
// what()   :   this is the fucntion name. what() is commonly used in exception classes to return a description of the error.
//              It is a member of the std::exception class
// const    :   this function will not modify any member variables of the class
// throw()  :   this has been deprecated from c++11. It is an exception specification and it tells the compiler this function will
//              not throw any exception. Only instances of the class can be thrown as exceptions.

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define GRADE_TOO_LOW "Grade can not be lower than 150"
#define GRADE_TOO_HIGH "Grade can not be higher than 1"
#define B_GRADE ", bureaucrat grade: "

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        const std::string &getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
