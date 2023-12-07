#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap (void) {std::cout<<CLAPTRAP_DEFAULT_CONSTRUCTOR;}

ClapTrap::ClapTrap (std::string name) {
	std::cout<<CLAPTRAP_CONSTRUCTOR<<name<<std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &ct) {
	std::cout<<CLAPTRAP_COPY_CONSTRUCTOR<<this->_name<<std::endl;
	*this = ct;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ct) {
	std::cout<<CLAPTRAP_COPY_ASSIGNMENT_OPERATOR;
	if (this == &ct)
		return (*this);
	this->setHp(ct.getHp());
	this->setEp(ct.getEp());
	this->setAd(ct.getAd());
	this->setName(ct.getName());
	return (*this);
}

void	ClapTrap::attack (const std::string& target) {
	if (this->_energyPoints <= 0) {
		std::cout<<this->_name<<NO_ENERGYPOINTS;
		return ;
	}
	std::cout<<this->_name<<CLAPTRAP_ATTACK_ONE<<target<<CLAPTRAP_ATTACK_TWO<<this->_attackDamage<<std::endl;
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout<<this->_name<<CLAPTRAP_ATTACKED<<amount<<CLAPTRAP_HEALING_TWO;
	this->_hitPoints-=amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints <= 0) {
		std::cout<<this->_name<<NO_ENERGYPOINTS;
		return ;
	}
	std::cout<<this->_name<<CLAPTRAP_HEALING_ONE<<amount<<CLAPTRAP_HEALING_TWO;
	this->_hitPoints+=amount;
}

int	ClapTrap::getHp(void) const {return (this->_hitPoints);}

int	ClapTrap::getEp(void) const {return (this->_energyPoints);}

int	ClapTrap::getAd(void) const {return (this->_attackDamage);}

std::string	ClapTrap::getName(void) const {return (this->_name);}

void	ClapTrap::setHp(int i) {this->_hitPoints = i;}

void	ClapTrap::setEp(int i) {this->_energyPoints = i;}

void	ClapTrap::setAd(int i) {this->_attackDamage = i;}

void	ClapTrap::setName(std::string name) {this->_name = name;}

ClapTrap::~ClapTrap (void) {std::cout<<CLAPTRAP_DECONSTRUCTOR<<this->_name<<std::endl;}
