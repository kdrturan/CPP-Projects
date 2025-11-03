#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : type(weaponType) {}
Weapon::Weapon() {}

Weapon::~Weapon() {}

std::string Weapon::getType() {
	return type;
}
void Weapon::setType(std::string weaponType) {
	type = weaponType;
}