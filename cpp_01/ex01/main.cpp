#include "includes/Zombie.hpp"

int main ()
{
	Zombie	*fratm;

	fratm= zombieHorde(13, "Katamarani");
	delete[] fratm;
	return (0);
}
