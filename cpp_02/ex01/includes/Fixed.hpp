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

		Fixed(void);
		Fixed(const Fixed &f); // Copy constructor
		Fixed(const int n);
		Fixed(const float fp);
		Fixed &operator=(const Fixed &f); // Copy assignment operator
		~Fixed(void);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif
