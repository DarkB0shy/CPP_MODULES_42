#include "../includes/Harl.hpp"

Harl::Harl () {}

void Harl::debug (void) {std::cout << HARL_DEBUG;}

void Harl::info (void) {std::cout << HARL_INFO;}

void Harl::warning (void) {std::cout << HARL_WARNING;}

void Harl::error (void) {std::cout << HARL_ERROR;}

void Harl::complain (std::string level)
{
	int	i;
	void	(Harl::*complain[4])(void) = {&Harl::debug,&Harl::info,&Harl::warning,&Harl::error,};
	std::string	func_level[4] = {"DEBUG","INFO","WARNING","ERROR"};

	i = -1;
	while (++i < 4)
		if (level == func_level[i])
			(this->*complain[i])();
}

Harl::~Harl () {}
