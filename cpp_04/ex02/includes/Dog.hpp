#ifndef DOG_H
#define DOG_H

#include "Aanimal.hpp"
#include "Brain.hpp"

#define DOG_CONST "Dog constructor was called.\n"
#define DOG_COPY_CONST "Dog copy constructor was called.\n"
#define DOG_COPY_ASS_OP "Dog copy assignment operator was called.\n"
#define DOG_DESTRUCTOR "Dog was destroyed.\n"
#define DOG_TYPE "Dog"
#define DOG_SOUND "Bark\n"

class Dog : public virtual Animal {
	private:
		Brain	*_brain;
	protected:
		std::string	_type;
	public:
		Dog(void);
		Dog (const Dog &d);
		Dog &operator=(const Dog &d);
		virtual void makeSound(void) const;
		~Dog(void);
};

#endif
