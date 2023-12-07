#include "../includes/Fixed.hpp"

Fixed::Fixed (void) {this->_number = 0;}

Fixed::Fixed (const Fixed &f) {*this = f;} //Copy constructor. Creates a copy

Fixed::Fixed (const int n) {this->_number = (n * (1 << this->_bits));}

Fixed::Fixed (const float fp) {this->_number = roundf(fp * (1 << this->_bits));}

Fixed	&Fixed::operator=(const Fixed &f) //Copy assignment operator. "Updates" the copy
{
	if (this == &f)
		return (*this);
	this->_number = f.getRawBits();
	return (*this);
}

float	Fixed::toFloat(void) const
{
	float	tmp;

	tmp = (((float)this->_number / (float)(1 << this->_bits)));
	return (tmp);
}

int	Fixed::toInt(void) const {return (roundf(this->toFloat()));}

void	Fixed::setRawBits(const int raw) {this->_number = raw;}

int	Fixed::getRawBits(void) const {return (this->_number);}

Fixed	&Fixed::operator+(const Fixed &fixed) {
	this->_number += fixed.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator-(const Fixed &fixed) {
	this->_number -= fixed.getRawBits();
	return (*this);
}

Fixed	&Fixed::operator*(const Fixed &fixed) {
	this->_number *= fixed.toFloat();
	return (*this);
}

Fixed	&Fixed::operator/(const Fixed &fixed) {
	this->_number /= fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator<(const Fixed &fixed) const {return (this->_number<fixed.getRawBits());}

bool	Fixed::operator>(const Fixed &fixed) const {return (this->_number>fixed.getRawBits());}

bool	Fixed::operator<=(const Fixed &fixed) const {return (this->_number<=fixed.getRawBits());}

bool	Fixed::operator>=(const Fixed &fixed) const {return (this->_number>=fixed.getRawBits());}

bool	Fixed::operator!=(const Fixed &fixed) const {return (this->_number!=fixed.getRawBits());}

bool	Fixed::operator==(const Fixed &fixed) const {return (this->_number==fixed.getRawBits());}

Fixed	&Fixed::operator++(void) {
	this->_number++;
	return (*this);
}

Fixed	&Fixed::operator--(void) {
	this->_number--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp;

	tmp = *this;
	this->_number++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp;

	tmp = *this;
	this->_number++;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed	&Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed::~Fixed (void) {}

std::ostream	&operator<<(std::ostream &out, const Fixed &f) {return (out << f.toFloat());}
