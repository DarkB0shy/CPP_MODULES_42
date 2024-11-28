#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

#define FORM_NOT_FOUND "The form you asked the intern for does not exist."

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern &inter);
        Intern &operator=(const Intern &inter);
        AForm* makeForm(std::string formName, std::string target);
        class FormNotFound : public std::exception {
            public:
                virtual const char * what() const throw();
        };
        static AForm *createPresidentialPardon(std::string target);             // The static keyword is needed because non-static member functions have a "hidden"
        static AForm *createRobotomyRequest(std::string target);                // "this->" pointer that does not allow them to be used with regular function pointers.
        static AForm *createShrubberyCreation(std::string target);              // Static or "free" functions do not have the hidden "this" pointer.
};

#endif