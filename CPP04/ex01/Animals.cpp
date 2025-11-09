#include "Animals.hpp"
#include <iostream>

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" <<  std::endl;
}

Dog::~Dog() {
	delete brain;	
	std::cout << "Dog destructor called" <<  std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" <<  std::endl;
}

void Dog::makeSound() const {
	std::cout << "HAAWWAWAWAWAWAWAWAWAWA!" << std::endl;
}


Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::setBrainIdea(int index, const std::string& idea) {
	brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
	return brain->getIdea(index);
}




Cat::Cat() {
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructor called" <<  std::endl;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" <<  std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" <<  std::endl;
}

void Cat::makeSound() const {
	std::cout << "Mi yaaooooav!" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}


void Cat::setBrainIdea(int index, const std::string& idea) {
	brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
	return brain->getIdea(index);
}