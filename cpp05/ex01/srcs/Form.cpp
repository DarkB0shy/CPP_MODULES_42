#include "../headers/Form.hpp"
#include "../headers/Bureaucrat.hpp"

Form::Form() : _name("noName"), _gradeToSign(42), _gradeToExecute(42) {}

Form::Form(const std::string &name, const int gts, const int gte) : _name(name), _gradeToSign(gts), _gradeToExecute(gte) {
    if (_gradeToSign > 150 || _gradeToExecute > 150) throw Form::GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExecute < 1) throw Form::GradeTooHighException();
    _isSigned = false;
}

Form::Form(const Form &fr) : _name(fr._name), _gradeToSign(fr._gradeToSign), _gradeToExecute(fr._gradeToExecute) {}

Form &Form::operator=(const Form &fr) {
    if (this != &fr) *this = Form(fr);
    return (*this); 
}

const std::string &Form::getName() const {return _name;}

bool Form::getIsSigned() const {return _isSigned;}

int Form::getGTS() const {return _gradeToSign;}

int Form::getGTE() const {return _gradeToExecute;}

const char * Form::GradeTooHighException::what() const throw() {return FORM_GRADE_TOO_HIGH;}

const char * Form::GradeTooLowException::what() const throw() {return FORM_GRADE_TOO_LOW;}

void Form::beSigned(Bureaucrat &bur) {
    if (bur.getGrade() > _gradeToSign) throw Form::GradeTooLowException();
    _isSigned = true;
}

Form::~Form() {}

std::ostream &operator<<(std::ostream &out, const Form &fr) {
    std::string isSigned;
    if (fr.getIsSigned()) isSigned = "Yes | "; else isSigned = "No | ";
    out<<FORM_INFO<<fr.getName() + " | "<<isSigned<<fr.getGTS()<<" | "<<fr.getGTE()<<std::endl;
    return (out);
}
