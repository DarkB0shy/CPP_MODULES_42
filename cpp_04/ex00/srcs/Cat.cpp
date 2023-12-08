#include "../includes/Cat.hpp"

Cat::Cat (void) {
	this->_type = CAT_TYPE;
	std::cout<<CAT_DEF_CONST;
}

Cat::Cat (const Cat &c) : Animal(c) {
	*this = c;
	std::cout<<CAT_COPY_CONST;
}

Cat	&Cat::operator=(const Cat &c) {
	if (this == &c)
		return (*this);
	this->_type = c._type;
	std::cout<<CAT_ASS_OP;
	return (*this);
}

void	Cat::makeSound (void) const {std::cout<<CAT_SOUND;}

Cat::~Cat (void) {std::cout<<CAT_DESTRUCTOR;}
