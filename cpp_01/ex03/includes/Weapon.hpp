#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <cstdlib>
#include <string>

#define ATTACK " attack with his "

class Weapon {

	private:
		std::string _type;

	public:
		std::string	getType(void);
		void		setType(std::string type);
		Weapon		(std::string type);
		~Weapon		(void);
};

#endif
