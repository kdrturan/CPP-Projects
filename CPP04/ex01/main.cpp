#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int size = 4;
	Animal *animals[size];

	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();

	for (int i = 0; i < size; i++)
		animals[i]->makeSound();

	for (int i = 0; i < size; i++)
		delete animals[i];

	std::cout << std::endl;

	Dog dog1;
	dog1.setBrainIdea(0, "food");

	Dog dog2(dog1);

	dog2.setBrainIdea(0, "sleep");

	std::cout << dog1.getBrainIdea(0) << std::endl;
	std::cout << dog2.getBrainIdea(0) << std::endl;

	return 0;
}
