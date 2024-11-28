#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>                                                            // There is no built int random number generator in c++ 98.

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &rrf);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rrf);
        void    execute(Bureaucrat const &executor) const;
};

#endif