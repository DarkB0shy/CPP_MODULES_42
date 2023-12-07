#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void) {std::cout<<FRAGTRAP_DEFAULT_CONSTRUCTOR;}

FragTrap::FragTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout<<FRAGTRAP_CONSTRUCTOR<<name<<std::endl;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft) {
	*this = ft;
	std::cout<<FRAGTRAP_COPY_CONSTRUCTOR;
}

FragTrap	&FragTrap::operator=(const FragTrap &ft) {
	if (this == &ft)
		return (*this);
	this->_name = ft.getName();
	this->_hitPoints = ft.getHp();
	this->_energyPoints = ft.getEp();
	this->_attackDamage = ft.getAd();
	return (*this);
}

void	FragTrap::highFiveGuys (void) {std::cout<<this->_name<<HIGH_FIVE_GUYS;}

FragTrap::~FragTrap(void) {std::cout<<FRAGTRAP_DECONSTRUCTOR<<this->_name<<std::endl;}
