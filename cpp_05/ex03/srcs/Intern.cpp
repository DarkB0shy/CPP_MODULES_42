#include "../headers/Intern.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &inter) {*this = inter;}

Intern  &Intern::operator=(const Intern &inter) {return *this;}

const char * Intern::FormNotFound::what() const throw() {return FORM_NOT_FOUND;}

AForm* Intern::createPresidentialPardon(std::string target) {										// These functions are needed in order to not create 3 froms everytime "makeForm" is called
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequest(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreation(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[] = {"Presidential pardon", "Robotomy request", "Shruberry creation"};
    AForm* (*formCreators[])(std::string) = {														// lambda functions are not allowed in c++98; subject stops you from using <map>, so this is one solution
        &Intern::createPresidentialPardon,
        &Intern::createRobotomyRequest,
        &Intern::createShrubberyCreation
    };
	AForm *newForm = nullptr;
	for (int i = 0; i < 3; ++i) {
		if (formNames[i] ==formName) {
			newForm = formCreators[i](target);
			break;
		}
	}
	if (newForm) std::cout << "Intern creates" << formName << std::endl;
	else throw Intern::FormNotFound();
    return newForm;
}