#include "Zombie.hpp"


int main() {
	randomChump("Etkafa");
	Zombie* zombie1 = newZombie("Yamyam");
	zombie1->announce();
	delete zombie1;
	return 0;
}