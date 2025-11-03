#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie( std::string zombieName) : name(zombieName) {}
Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << name << " is destroyed.May God have mercy on him." << std::endl;
}

void Zombie::setName(std::string zombieName) {
	name = zombieName;
}

void Zombie::announce() const {
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}