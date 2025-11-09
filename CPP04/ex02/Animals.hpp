#ifndef	ANIMALS_HPP
#define	ANIMALS_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Dog : public Animal {
private:
	Brain* brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog& other);
	virtual void makeSound() const;
	Dog& operator=(const Dog& other);
	void setBrainIdea(int index, const std::string& idea);
	std::string getBrainIdea(int index) const;
};

class Cat : public Animal {
private:
	Brain* brain;
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& other);
	virtual void makeSound() const;
	Cat& operator=(const Cat& other);
	void setBrainIdea(int index, const std::string& idea);
	std::string getBrainIdea(int index) const;
};

#endif