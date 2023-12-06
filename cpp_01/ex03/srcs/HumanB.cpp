#include "../includes/HumanB.hpp"

HumanB::HumanB (std::string name) {this->_name = name;}

void	HumanB::attack (void) {std::cout << this->_name << ATTACK << this->_wpn->getType() << std::endl;}

void	HumanB::setWeapon (Weapon &wpn) {this->_wpn = &wpn;}

HumanB::~HumanB (void) {}
