#include "../includes/Dog.hpp"

Dog::Dog (void) {
	this->_type = DOG_TYPE;
	std::cout<<DOG_CONST;
}

Dog::Dog (const Dog &d) : Animal(d) {
	*this = d;
	std::cout<<DOG_COPY_CONST;
}

Dog	&Dog::operator=(const Dog &d) {
	if (this == &d)
		return (*this);
	this->_type = d._type;
	std::cout<<DOG_COPY_ASS_OP;
	return (*this);
}

void	Dog::makeSound (void) const {std::cout<<DOG_SOUND;}

Dog::~Dog (void) {std::cout<<DOG_DESTRUCTOR;}
