#include "includes/Cat.hpp"
#include "includes/Dog.hpp"

int main (void)
{
	const Animal* tom = new Cat();
	const Animal* goofy = new Dog();
//	const Animal* nosir = new Animal();

	tom->makeSound();
	goofy->makeSound();
	delete goofy;
	delete tom;
	return (0);
}
