#include "includes/Cat.hpp"
#include "includes/Dog.hpp"
#include "includes/WrongCat.hpp"

int main (void)
{
	const Animal* diego = new Animal();
	const Animal* tom = new Cat();
	const Animal* goofy = new Dog();
	const WrongAnimal *tragic = new WrongAnimal();
	const WrongCat *genovesi = new WrongCat();

	diego->makeSound();
	tom->makeSound();
	goofy->makeSound();
	tragic->makeSound();
	genovesi->makeSound();
	delete genovesi;
	delete tragic;
	delete goofy;
	delete tom;
	delete diego;
	return (0);
}
