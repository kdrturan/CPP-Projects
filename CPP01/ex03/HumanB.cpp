#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string humanName) : name(humanName) {}
HumanB::~HumanB() {}

void HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& humanWeapon) {
	weapon = &humanWeapon;
}