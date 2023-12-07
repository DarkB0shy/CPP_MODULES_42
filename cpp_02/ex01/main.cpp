#include "includes/Fixed.hpp"

int main (void)
{
	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);

	a = Fixed(1234.4321f);
	std::cout<<"A: "<<a<<std::endl;
	std::cout<<"B: "<<b<<std::endl;
	std::cout<<"C: "<<c<<std::endl;
	std::cout<<"D: "<<d<<std::endl;
	std::cout<<"A as integer: "<<a.toInt()<<std::endl;
	std::cout<<"B as integer: "<<b.toInt()<<std::endl;
	std::cout<<"C as integer: "<<c.toInt()<<std::endl;
	std::cout<<"D as integer: "<<d.toInt()<<std::endl;
	return (0);
}
