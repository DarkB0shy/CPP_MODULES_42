#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define SCAVTRAP_DEFAULT_CONSTRUCTOR "A scavtrap was created.\n"
#define SCAVTRAP_CONSTRUCTOR "Scavtrap was created: "
#define SCAVTRAP_COPY_CONSTRUCTOR "Scavtrap copy constructor called.\n"
#define SCAVTRAP_COPY_ASSIGNMENT_OPERATOR "Scavtrap copy assignment operator called.\n"
#define SCAVTRAP_DECONSTRUCTOR "Scavtrap destroyed: "
#define SCAVTRAP_GUARDGATE " is now in gate keeper mode.\n"

class ScavTrap : public virtual ClapTrap {
	public:
		void	guardGate(void);

		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &st);
		ScavTrap &operator=(const ScavTrap &ct);
		virtual ~ScavTrap();
};

#endif
