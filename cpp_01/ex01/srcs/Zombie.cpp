#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) {this->_name = name;}

void	Zombie::set_name(std::string name) {this->_name = name;}

void	Zombie::announce(void) {std::cout<<this->_name<<BRAINZ;}

Zombie::~Zombie(void) {std::cout<<this->_name<<RESTS_IN_PIECES;}

Zombie*	newZombie(std::string name)
{
	Zombie	*land;

	land = new Zombie(name);
	return (land);
}
