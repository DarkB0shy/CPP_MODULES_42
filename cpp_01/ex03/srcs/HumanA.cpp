#include "../includes/HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &wpn)
{
	this->_name = name;
	this->_wpn = &wpn;
}

void	HumanA::attack () {std::cout << this->_name << ATTACK << this->_wpn->getType() << std::endl;}

HumanA::~HumanA () {}
