#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define ANIMAL_DEF_CONST "Animal default constructor call for: "
#define ANIMAL_CONST "Animal constructor call for: "
#define ANIMAL_COPY_CONST "Animal copy constructor call.\n"
#define ANIMAL_COPY_ASS_OP "Animal copy assignment operator called.\n"
#define ANIMAL_DECONSTRUCTOR "Animal deconstructor call for: "
#define ANIMAL_TYPE "Strano animalo"
#define ANIMAL_SOUND "Eccezziunale\n"

class Animal {
	protected:
		std::string	_type;
	public:
		virtual void	makeSound(void) const = 0;
		std::string	getType(void) const;
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &a);
		Animal &operator=(const Animal &a);
		virtual ~Animal();
};

#endif
