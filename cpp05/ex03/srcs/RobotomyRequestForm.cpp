#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("nan", 72, 45), _target("target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) {*this = rrf;}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf) {return *this;}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    this->checkFormReq(executor);
    std::cout << "DRILL NOISES" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(0)));
    if (int ran_val = std::rand() % 2) std::cout << this->_target << " has been succesfully robotomized." << std::endl;
    else std::cout << "The robotomy has failed." << std::endl;
}