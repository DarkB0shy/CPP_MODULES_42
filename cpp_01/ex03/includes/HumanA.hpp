#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {
	private:
		Weapon		*_wpn;
		std::string	_name;

	public:
		void	attack(void);
		HumanA(std::string name, Weapon &wpn);
		~HumanA(void);
};

#endif
