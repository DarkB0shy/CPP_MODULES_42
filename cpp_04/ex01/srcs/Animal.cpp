#include "../includes/Animal.hpp"

Animal::Animal (void) {
	this->_type = ANIMAL_TYPE;
	std::cout<<ANIMAL_DEF_CONST<<this->_type<<std::endl;
}

Animal::Animal (std::string type) {
	this->_type = type;
	std::cout<<ANIMAL_CONST<<type<<std::endl;
}

Animal::Animal (const Animal &a) {
	*this = a;
	std::cout<<ANIMAL_COPY_CONST;
}

Animal	&Animal::operator=(const Animal &a) {
	if (this == &a)
		return (*this);
	this->_type = a._type;
	std::cout<<ANIMAL_COPY_ASS_OP;
	return (*this);
}

void	Animal::makeSound (void) const {std::cout<<ANIMAL_SOUND;}

std::string	Animal::getType (void) const {return this->_type;}

Animal::~Animal (void) {std::cout<<ANIMAL_DECONSTRUCTOR<<this->_type<<std::endl;}
