#include "includes/ScavTrap.hpp"

int main (void)
{
	ScavTrap c1("Barba Streisand"); 
	ScavTrap c2(c1);
	ScavTrap c3;

	c3 = c1;
	c2.setName("Toblerone");
	c3.setName("Malandrone");
	c1.guardGate();
	c2.guardGate();
	c3.guardGate();
	return (0);
}
