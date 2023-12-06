#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define HARL_DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n"
#define HARL_INFO "I cannot believe adding extra bacon costs more money. You did not put enough bacon in my burger! If you did, I would not be asking for more!\n"
#define HARL_WARNING "I think I deserve to have some extra bacon for free. I have been coming for years whereas you started working here since last month.\n"
#define HARL_ERROR "This is unacceptable! I want to speak to the manager now.\n"

class Harl {
	private:
		void	debug	(void);
		void	info	(void);
		void	warning	(void);
		void	error	(void);
	public:
		void	complain(std::string level);
		Harl();
		~Harl();
};

#endif
