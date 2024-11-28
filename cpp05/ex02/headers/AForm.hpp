// A virtual method makes a class abstract meaning it can not be instantiated. Any method can be made virtual, but it should be the one method that will be
// overridden by classes that derive from this one and which behaviour should change amongst them. 

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
class Bureaucrat;

#define FORM_INFO "Form's name, status (signed/non-signed), grade to sign and grade to execute: "
#define FORM_GRADE_TOO_LOW "The grade is too low for this form."
#define FORM_GRADE_TOO_HIGH "The grade is too high for this form."
#define FORM_NOT_SIGNED "You must first sign the form if you wish to execute it."

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        AForm(const std::string &name, const int gts, const int gte);
        AForm(const AForm &fr);
        AForm &operator=(const AForm &fr);
        ~AForm();
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
        class FormNotSigned : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        void checkFormReq(Bureaucrat const & executor) const;
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &fr);

#endif