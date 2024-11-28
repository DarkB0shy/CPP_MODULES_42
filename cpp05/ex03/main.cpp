#include "headers/Bureaucrat.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"
#include "headers/Intern.hpp"

int main() {
    try {
        Intern lameintern;
        AForm* myForm = lameintern.makeForm("notAForm", "notATarget");
    } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    try {
        std::cout << std::endl;
        Intern lameintern;
        AForm *vipForm = lameintern.makeForm("Presidential pardon", "God");
        Bureaucrat Jesus("Jesus", 1);
        Jesus.signForm(*vipForm);
        std::cout << *vipForm;
        Jesus.executeForm(*vipForm);
    } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    return (0);
}
