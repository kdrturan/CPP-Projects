#include "Animal.hpp"
#include "Animals.hpp"


int main()
{
	Animal* animals[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	std::cout << "\nDeleting animals:" << std::endl;
	for (int i = 0; i < 10; i++) {
		delete animals[i];
	}

	std::cout << "\nAfter delete:" << std::endl;


	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();

	dog1->setBrainIdea(0, "Chasing cats");
	std::cout << "Dog1 Brain Idea[0]: " << dog1->getBrainIdea(0) << std::endl;
	*dog2 = *dog1;
	std::cout << "Dog2 Brain Idea[0]: " << dog2->getBrainIdea(0) << std::endl;
	dog1->setBrainIdea(0, "Eating bones");
	std::cout << "\nAfter modifying Dog1's brain idea:" << std::endl;
	std::cout << "Dog1 Brain Idea[0]: " << dog1->getBrainIdea(0) << std::endl;
	std::cout << "Dog2 Brain Idea[0]: " << dog2->getBrainIdea(0) << std::endl;
	delete dog1;
	delete dog2;

	std::cout << "\nCats Constructors:" << std::endl;
	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat();
	cat1->setBrainIdea(0, "Chasing mice");
	std::cout << "Cat1 Brain Idea[0]: " << cat1->getBrainIdea(0) << std::endl;
	*cat2 = *cat1;
	std::cout << "Cat2 Brain Idea[0]: " << cat2->getBrainIdea(0) << std::endl;
	cat1->setBrainIdea(0, "Sleeping all day");
	std::cout << "\nAfter modifying Cat1's brain idea:" << std::endl;
	std::cout << "Cat1 Brain Idea[0]: " <<	 cat1->getBrainIdea(0) << std::endl;
	std::cout << "Cat2 Brain Idea[0]: " << cat2->getBrainIdea(0) << std::endl;
	delete cat1;
	delete cat2;

	return 0;
}