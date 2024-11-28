#include "headers/Bureaucrat.hpp"
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"

int main() {
    // AForm notForm("VIP", 42, 42);
    try {
        ShrubberyCreationForm ttt;
        Bureaucrat nick;
        std::cout << ttt;
        ttt.execute(nick);                                                      // execute() will print a message only if <form> didn't get executed
    } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    try {
        std::cout << std::endl;
        ShrubberyCreationForm sss("STARGET");
        std::cout << sss;
        Bureaucrat rick("rick", 37);
        std::cout << rick;
        rick.signForm(sss);
        rick.executeForm(sss);
        Bureaucrat toby("toby", 139);
        std::cout << toby;
        sss.execute(toby);
        } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    try {
        std::cout << std::endl;
        RobotomyRequestForm zzz("EARTH");
        std::cout << zzz;
        Bureaucrat freddie("freddie", 21);
        freddie.signForm(zzz);
        freddie.executeForm(zzz);
    } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    try {
        std::cout << std::endl;
        PresidentialPardonForm ppf("Lord Megazord");
        std::cout << ppf;
        Bureaucrat randersen("randersen", 1);
        std::cout << randersen;
        Bureaucrat bubbles("bubbles", 79);
        randersen.signForm(ppf);
        randersen.executeForm(ppf);
        bubbles.executeForm(ppf);
    } catch (std::exception &e) {std::cerr << e.what() << std::endl;}
    return (0);
}
