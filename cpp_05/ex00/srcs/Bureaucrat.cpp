#include "../headers/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Percivald"), _grade(149) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _grade = other._grade;
        // _name = other._name;         _name is const
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {return _name;}

int Bureaucrat::getGrade() const {return _grade;}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1) throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150) throw Bureaucrat::GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {return GRADE_TOO_HIGH;}

const char* Bureaucrat::GradeTooLowException::what() const throw() {return GRADE_TOO_LOW;}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
    out<<bureaucrat.getName()<<B_GRADE<<bureaucrat.getGrade()<<std::endl;
    return (out);
}
