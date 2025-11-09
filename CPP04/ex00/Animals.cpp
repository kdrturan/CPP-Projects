#include "Animals.hpp"
#include <iostream>

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructor called" <<  std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" <<  std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" <<  std::endl;
}

void Dog::makeSound() const {
	std::cout << "HAAWWAWAWAWAWAWAWAWAWA!" << std::endl;
}


Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructor called" <<  std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" <<  std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" <<  std::endl;
}

void Cat::makeSound() const {
	std::cout << "Mi yaaooooav!" << std::endl;
}


