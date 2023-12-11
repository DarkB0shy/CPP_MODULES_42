#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal (void) {
	this->_type = WANIMAL_TYPE;
	std::cout<<WANIMAL_CONSTRUCTOR<<this->_type<<std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal &wa) {
	*this = wa;
	std::cout<<WANIMAL_COPY_CONST;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wa) {
	if (this == &wa)
		return (*this);
	this->_type = wa._type;
	std::cout<<WANIMAL_COPY_ASS_OP;
	return (*this);
}

void	WrongAnimal::makeSound (void) const {std::cout<<WANIMAL_SOUND;}

WrongAnimal::~WrongAnimal(void) {std::cout<<WANIMAL_DESTRUCTOR<<this->_type<<std::endl;}
