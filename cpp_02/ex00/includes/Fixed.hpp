#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int			_number;
		static const int	_bits = 8;
	public:
		void		setRawBits(int const raw);
		int		getRawBits(void) const;

		Fixed(void);
		Fixed(const Fixed &f); // Copy constructor
		Fixed &operator=(const Fixed &f); // Copy assignment operator
		~Fixed(void);
};

#endif
