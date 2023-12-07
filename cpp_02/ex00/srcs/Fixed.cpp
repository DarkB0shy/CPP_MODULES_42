#include "../includes/Fixed.hpp"

Fixed::Fixed (void) {this->_number = 0;}

Fixed::Fixed (const Fixed &f) {*this = f;} //Copy constructor. Creates a copy

Fixed	&Fixed::operator=(const Fixed &n) //Copy assignment operator. "Updates" the copy
{
	if (this == &n)
		return (*this);
	this->_number = n.getRawBits();
	return *(this);
}

void	Fixed::setRawBits(const int raw) {this->_number = raw;}

int	Fixed::getRawBits(void) const {return (this->_number);}

Fixed::~Fixed (void) {}
