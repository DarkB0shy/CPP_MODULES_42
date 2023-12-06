#include "PhoneBook.hpp"
#include "PhoneBook.cpp"
#include "Contact.cpp"
#include "Contact.hpp"

int main (void)
{
	PhoneBook Guarnito;

	Guarnito.phoneBookLoop();
	std::cout << std::endl;
	return (0);
}
