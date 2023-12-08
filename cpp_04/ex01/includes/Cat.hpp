#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define CAT_DEF_CONST "Cat default constructor was called.\n"
#define CAT_COPY_CONST "Cat copy constructor was called.\n"
#define CAT_ASS_OP "Cat copy assignment operator was called.\n"
#define CAT_DESTRUCTOR "Cat was destroyed.\n"
#define CAT_TYPE "Cat"
#define CAT_SOUND "Miao\n"

class Cat : public virtual Animal {
	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(const Cat &c);
		Cat &operator=(const Cat &c);
		virtual void makeSound(void) const;
		virtual ~Cat(void);
};

#endif
