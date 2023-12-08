#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int main (void)
{
	const Animal	*zoo[10];
	int		i = -1;

	while (++i < 10)
	{
		if (i % 2)
			zoo[i] = new Cat();
		else
			zoo[i] = new Dog();
	}
	i =-1;
	while (++i < 10)
		delete zoo[i];
	return (0);
}
