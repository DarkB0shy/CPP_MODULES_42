#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

#define RESTS_IN_PIECES " is now flesh for the fishes.\n"
#define BRAINZ ": BraiiiiinnzzZ...\n"

class Zombie {

	private:
		std::string	_name;

	public:
		void		set_name(std::string name);
		void		announce(void);

		Zombie	();
		Zombie	(std::string name);
		~Zombie	();
};

Zombie*	newZombie(std::string name);
Zombie*	zombieHorde(int N, std::string name);

#endif
