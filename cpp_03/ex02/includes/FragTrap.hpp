#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define FRAGTRAP_DEFAULT_CONSTRUCTOR "A fragtrap was created.\n"
#define FRAGTRAP_CONSTRUCTOR "Fragtrap was created: "
#define FRAGTRAP_COPY_CONSTRUCTOR "Fragtrap copy constructor called.\n"
#define FRAGTRAP_COPY_ASSIGNMENT_OPERATOR "Fragtrap copy assignment operator called.\n"
#define FRAGTRAP_DECONSTRUCTOR "Fragtrap destroyed: "
#define HIGH_FIVE_GUYS " positively asks for an high five!\n"

class FragTrap : public virtual ClapTrap {
	public:
		void	highFiveGuys(void);

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &ft);
		FragTrap &operator=(const FragTrap &ft);
		virtual ~FragTrap(void);
};

#endif
