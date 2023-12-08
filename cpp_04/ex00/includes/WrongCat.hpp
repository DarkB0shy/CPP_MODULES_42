#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#define WCAT_DEF_CONST "Wrong cat default constructor was called.\n"
#define WCAT_COPY_CONST "Wrong cat copy constructor was called.\n"
#define WCAT_COPY_ASS_OP "Wrong cat copy assignment operator was called.\n"
#define WCAT_DESTRUCTOR "Wrong cat was destroyed.\n"
#define WCAT_TYPE "Notcat"
#define WCAT_SOUND "Coccode\n"

class WrongCat : public virtual WrongAnimal {
	public:
		virtual void makeSound(void) const;
		WrongCat(void);
		WrongCat(const WrongCat &wc);
		WrongCat &operator=(const WrongCat &wc);
		virtual ~WrongCat(void);
};

#endif
