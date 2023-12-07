#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int			_number;
		static const int	_bits = 8;
	public:
		void		setRawBits(int const raw);
		int		getRawBits(void) const;
		float		toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator=(const Fixed &fixed);
		Fixed	&operator+(const Fixed &fixed);
		Fixed	&operator-(const Fixed &fixed);
		Fixed	&operator*(const Fixed &fixed);
		Fixed	&operator/(const Fixed &fixed);
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		bool operator<(const Fixed &fixed) const;
		bool operator>(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		static Fixed 		&min(Fixed &f1, Fixed &f2);
		static const Fixed 	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
		Fixed(void);
		Fixed(const Fixed &f); // Copy constructor
		Fixed(const int n);
		Fixed(const float fp);
		~Fixed(void);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif
