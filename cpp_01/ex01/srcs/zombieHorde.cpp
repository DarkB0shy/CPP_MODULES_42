#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {}

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *hoard;
	int	i;

	hoard = new Zombie[N];
	i = -1;
	while (++i < N)
	{
		hoard[i].set_name(name);
		hoard[i].announce();
	}
	return (hoard);
}
