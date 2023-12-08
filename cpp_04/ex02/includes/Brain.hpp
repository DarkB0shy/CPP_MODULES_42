#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define BRAIN_DEF_CONST "Brain default constructor called.\n"
#define BRAIN_COPY_CONST "Brain copy constructor called.\n"
#define BRAIN_COPY_ASS_OP "Brain copy assignment operator called.\n"
#define BRAIN_DESTRUCTOR "Brain destructor methoed called.\n"

class Brain {
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(const Brain &b);
		Brain &operator=(const Brain &b);
		~Brain(void);
};

#endif
