#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#define WANIMAL_CONSTRUCTOR "Wrong animal constructor call for: "
#define WANIMAL_COPY_CONST "Wrong animal copy constructor called.\n"
#define WANIMAL_COPY_ASS_OP "Wrong animal copy assignment operator called.\n"
#define WANIMAL_DESTRUCTOR "Wrong animal deconstructor call for: "
#define WANIMAL_TYPE "Aniomalio strianio"
#define WANIMAL_SOUND "Nooo amio\n"

class WrongAnimal {
	protected:
		std::string	_type;
	public:
		std::string getType(void) const;
		virtual void makeSound(void) const;
		WrongAnimal (void);
		WrongAnimal (const WrongAnimal &wa);
		WrongAnimal &operator=(const WrongAnimal &wa);
		virtual ~WrongAnimal(void);
};

#endif
