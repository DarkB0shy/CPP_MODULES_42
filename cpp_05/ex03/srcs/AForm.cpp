#include "../headers/AForm.hpp"
#include "../headers/Bureaucrat.hpp"

AForm::AForm(const std::string &name, const int gts, const int gte) : _name(name), _gradeToSign(gts), _gradeToExecute(gte) {
    if (_gradeToSign > 150 || _gradeToExecute > 150) throw AForm::GradeTooLowException();
    if (_gradeToSign < 1 || _gradeToExecute < 1) throw AForm::GradeTooHighException();
    _isSigned = false;
}

AForm::AForm() : _name("nan"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const AForm &fr) : _name(fr._name), _gradeToSign(fr._gradeToSign), _gradeToExecute(fr._gradeToExecute) {}

AForm &AForm::operator=(const AForm &fr) {
    if (this != &fr) this->_isSigned = fr.getIsSigned();
    return (*this); 
}

const std::string &AForm::getName() const {return _name;}

bool AForm::getIsSigned() const {return _isSigned;}

int AForm::getGTS() const {return _gradeToSign;}

int AForm::getGTE() const {return _gradeToExecute;}

std::ostream &operator<<(std::ostream &out, const AForm &fr) {
    std::string isSigned;
    if (fr.getIsSigned()) isSigned = "Yes | "; else isSigned = "No | ";
    out<<FORM_INFO<<fr.getName() + " | "<<isSigned<<fr.getGTS()<<" | "<<fr.getGTE()<<std::endl;
    return (out);
}

const char * AForm::GradeTooHighException::what() const throw() {return FORM_GRADE_TOO_HIGH;}

const char * AForm::GradeTooLowException::what() const throw() {return FORM_GRADE_TOO_LOW;}

const char * AForm::FormNotSigned::what() const throw() {return FORM_NOT_SIGNED;}

void AForm::beSigned(Bureaucrat &bur) {
    if (bur.getGrade() > _gradeToSign) throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::checkFormReq(Bureaucrat const & executor) const {
    if (!this->_isSigned) throw AForm::FormNotSigned();
    if (executor.getGrade() > this->_gradeToExecute) throw AForm::GradeTooLowException();
    else return ;
}

// void AForm::execute(Bureaucrat const & executor) const {}

AForm::~AForm() {}