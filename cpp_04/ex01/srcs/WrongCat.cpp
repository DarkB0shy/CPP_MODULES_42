#include "../includes/WrongCat.hpp"

WrongCat::WrongCat (void) {
	this->_type = WCAT_TYPE;
	std::cout<<WCAT_DEF_CONST;
}

WrongCat::WrongCat (const WrongCat &wc) : WrongAnimal (wc) {
	*this = wc;
	std::cout<<WCAT_COPY_CONST;
}

WrongCat	&WrongCat::operator=(const WrongCat &wc) {
	if (this == &wc)
		return (*this);
	this->_type = wc._type;
	std::cout<<WCAT_COPY_ASS_OP;
	return (*this);
}

void	WrongCat::makeSound (void) const {std::cout<<WCAT_SOUND;}

WrongCat::~WrongCat (void) {std::cout<<WCAT_DESTRUCTOR;}
