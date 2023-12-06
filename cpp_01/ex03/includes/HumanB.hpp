#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {
	private:
		Weapon		*_wpn;
		std::string 	_name;
	public:
		void	attack(void);
		void	setWeapon(Weapon &wpn);
		HumanB(std::string name);
		~HumanB(void);
};

#endif
