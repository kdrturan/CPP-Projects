#include "Animal.hpp"
#include "Animals.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nTypes:" << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	std::cout << "\nSounds:" << std::endl;
	i->makeSound(); 
	j->makeSound();
	meta->makeSound();

	std::cout << "\nDeleting animals:" << std::endl;
	delete j;
	delete i;
	delete meta;
	return 0;
}