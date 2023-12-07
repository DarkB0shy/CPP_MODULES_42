#include "includes/FragTrap.hpp"

int main (void)
{
	ClapTrap c1("Signor Mario");
	FragTrap f1("Johnny");
	ScavTrap s1("Montante");

	c1.beRepaired(333);
	s1.guardGate();
	f1.highFiveGuys();
	return (0);
}
