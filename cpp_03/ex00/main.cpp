#include "includes/ClapTrap.hpp"

void	fight(void)
{
	ClapTrap c1("Jennifer Aniston");
	ClapTrap c2("Barbra Streisand");
	ClapTrap c3("Sandra Bullock");
	ClapTrap c4("Snoop Dogg");

	c1.setHp(1024);
	c2.setHp(1024);
	c3.setHp(1024);
	c4.setHp(420);

	c1.setAd(43);
	c2.setAd(353);
	c3.setAd(157);
	c4.setAd(420);

	c1.attack(c2.getName());
	c2.takeDamage(c1.getAd());
	c1.attack(c2.getName());
	c2.takeDamage(c1.getAd());
	c1.attack(c2.getName());
	c2.takeDamage(c1.getAd());
	c2.attack(c1.getName());
	c1.takeDamage(c2.getAd());
	c3.attack(c1.getName());
	c1.takeDamage(c3.getAd());
	c1.attack(c4.getName());
	c4.takeDamage(c1.getAd());
	c4.beRepaired(c4.getAd());
	c4.beRepaired(c4.getAd());
	c4.beRepaired(c4.getAd());
	c4.beRepaired(c4.getAd());
	c4.beRepaired(c4.getAd());
	c4.beRepaired(c4.getAd());
}

int main(void)
{
	fight();
	return (0);
}
