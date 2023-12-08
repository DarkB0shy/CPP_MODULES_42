#include "../includes/Brain.hpp"

Brain::Brain (void) {std::cout<<BRAIN_DEF_CONST;}

Brain::Brain (const Brain &a) {
	*this = a;
	std::cout<<BRAIN_COPY_CONST;
}

Brain	&Brain::operator=(const Brain &b) {
	int i = -1;

	std::cout<<BRAIN_COPY_ASS_OP;
	if (this == &b)
		return (*this);
	while (++i < 100)
		this->_ideas[i] = b._ideas[i];
	return (*this);
}

Brain::~Brain (void) {std::cout<<BRAIN_DESTRUCTOR;}
