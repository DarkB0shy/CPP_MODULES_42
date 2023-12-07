#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define CLAPTRAP_DEFAULT_CONSTRUCTOR "A claptrap was created.\n"
#define CLAPTRAP_CONSTRUCTOR "Claptrap created: "
#define CLAPTRAP_COPY_CONSTRUCTOR "Copy constructor method called from: "
#define CLAPTRAP_COPY_ASSIGNMENT_OPERATOR "Claptrap copy assignment operator called.\n"
#define CLAPTRAP_DECONSTRUCTOR "Claptrap destroyed: "
#define NO_ENERGYPOINTS " the claptrap has not enough energy points!\n"
#define CLAPTRAP_ATTACK_ONE " has attacked "
#define CLAPTRAP_ATTACK_TWO "! Damage dealt: "
#define CLAPTRAP_ATTACKED " has now -"
#define CLAPTRAP_HEALING_ONE " heals for: "
#define CLAPTRAP_HEALING_TWO " hp!\n"

class ClapTrap {
	private:
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;
		std::string	_name;
	public:
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		int		getHp(void) const;
		int		getEp(void) const;
		int		getAd(void) const;
		std::string	getName(void) const;
		void		setHp(int i);
		void		setEp(int i);
		void		setAd(int i);
		void		setName(std::string name);
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &ct);
		ClapTrap &operator=(const ClapTrap &ct);
		~ClapTrap(void);
};

#endif
