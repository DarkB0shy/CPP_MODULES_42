#include "headers/Bureaucrat.hpp"
#include "headers/Form.hpp"

int main() {
    try {
        Form veryOldForm("VOF", 1, 151);
        } catch (std::exception &e) {std::cerr<<"Exception: "<<e.what()<<std::endl;}
    try {
        Form oldForm("OF", 0, 2);
        } catch (std::exception &e) {std::cerr<<"Exception: "<<e.what()<<std::endl;}
    try {
        Bureaucrat bob("Bob", 1);
        std::cout << bob;
        Form newForm;
        std::cout << newForm;
        newForm.beSigned(bob);
        std::cout << newForm;
        // std::cout << "The form was signed by Bob." << std::endl;
        Bureaucrat rat("Rat", 150);
        std::cout << rat;
        newForm.beSigned(rat);
        } catch (std::exception &e) {std::cerr<<"Exception: "<<e.what()<<std::endl;}
    try {
        Bureaucrat bob("bob", 1);
        std::cout << bob;
        Form newForm("VIP", 42, 69);
        std::cout << newForm;
        bob.signForm(newForm);
        std::cout << newForm;
        Bureaucrat rat("rat", 43);
        rat.signForm(newForm);
        } catch (std::exception &e) {std::cerr<<"Exception: "<<e.what()<<std::endl;}
    return (0);
}
