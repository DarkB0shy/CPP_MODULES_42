#include "includes/Zombie.hpp"

int main (void)
{
	Zombie	*landia;
	Zombie	arte("Neparte");

	arte.announce();

	landia = newZombie("Patroclo");
	landia->announce();
	delete landia;

	randomChump("Gernizio");

	return (0);
}
