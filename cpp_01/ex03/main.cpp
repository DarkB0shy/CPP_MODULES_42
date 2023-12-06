#include "includes/HumanA.hpp"
#include "includes/HumanB.hpp"

int main (void)
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("bob", club);
		bob.attack();
		club.setType("hyper lazor gun");
		bob.attack();
	}
	{
		Weapon newClub = Weapon("fluffy club");
		HumanB jim("Jim");
		jim.setWeapon(newClub);
		jim.attack();
		newClub.setType("hypercontinental death shuttle");
		jim.attack();
	}
	std::cout << std::endl;
	return (0);
}
