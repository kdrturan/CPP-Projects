#ifndef	ANIMALS_HPP
#define	ANIMALS_HPP
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog& other);
	virtual void makeSound() const;
};

class Cat : public Animal {
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& other);
	virtual void makeSound() const;
};

#endif