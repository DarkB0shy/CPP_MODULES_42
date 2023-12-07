#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {std::cout<<SCAVTRAP_DEFAULT_CONSTRUCTOR;}

ScavTrap::ScavTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout<<SCAVTRAP_CONSTRUCTOR<<name<<std::endl;
}

ScavTrap::ScavTrap (const ScavTrap &st) : ClapTrap (st) {
	*this = st;
	std::cout<<SCAVTRAP_COPY_CONSTRUCTOR;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &st) {
	if (this == &st)
		return (*this);
	this->_name = st.getName();
	this->_hitPoints = st.getHp();
	this->_energyPoints = st.getEp();
	this->_attackDamage = st.getAd();
	return (*this);
	std::cout<<SCAVTRAP_COPY_ASSIGNMENT_OPERATOR;
}

void	ScavTrap::guardGate(void) {std::cout<<this->_name<<SCAVTRAP_GUARDGATE;}

ScavTrap::~ScavTrap (void) {std::cout<<SCAVTRAP_DECONSTRUCTOR<<this->_name<<std::endl;}
