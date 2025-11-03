#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie(std::string zombieName);
		Zombie();
		~Zombie();
		void announce() const;
		void setName(std::string zombieName);
};

Zombie* zombieHorde(int N, std::string name );
#endif