#include "../includes/Fixed.hpp"

Fixed::Fixed (void) {this->_number = 0;}

Fixed::Fixed (const Fixed &f) {*this = f;} //Copy constructor. Creates a copy

Fixed::Fixed (const int n) {this->_number = n * 256;} // 256 == 1 << n_bits (n_bits == 8)

Fixed::Fixed (const float fp) {this->_number = roundf(fp * 256);}

Fixed	&Fixed::operator=(const Fixed &f) //Copy assignment operator. "Updates" the copy
{
	if (this == &f)
		return (*this);
	this->_number = f.getRawBits();
	return (*this);
}

float	Fixed::toFloat(void) const {return ((float)this->_number / 256.0);}

int	Fixed::toInt(void) const {return (roundf(this->toFloat()));}

void	Fixed::setRawBits(const int raw) {this->_number = raw;}

int	Fixed::getRawBits(void) const {return (this->_number);}

Fixed::~Fixed (void) {}

std::ostream	&operator<<(std::ostream &out, const Fixed &f) {return (out << f.toFloat());}
