#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

#define FORM_INFO "Form's name, status (signed/non-signed), grade to sign and grade to execute: "
#define FORM_GRADE_TOO_LOW "The grade is too low for this form."
#define FORM_GRADE_TOO_HIGH "The grade is too high for this form."

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        Form();
        Form(const std::string &name, const int gts, const int gte);
        Form(const Form &fr);
        Form &operator=(const Form &fr);
        ~Form();
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        const std::string &getName() const;
        bool getIsSigned() const;
        int getGTS() const;
        int getGTE() const;
        void beSigned(Bureaucrat &br);
};

std::ostream &operator<<(std::ostream &out, const Form &fr);

#endif