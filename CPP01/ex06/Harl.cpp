#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";

}
Harl::~Harl() {}

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}	

void Harl::insignificant( void ) {
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

int Harl::getLevelIndex(std::string level) {
	for (size_t i = 0; i < 4; i++) {
		if (level == levels[i]) {
			return i;
		}
	}
	return -1;
}

void Harl::complain( std::string level ) {
	int index = getLevelIndex(level);
	switch (index)
	{
	case 0:
		this->debug();
		this->info();
		this->warning();
		this->error();
		break;
	case 1:
		this->info();
		this->warning();
		this->error();
		break;
	case 2:
		this->warning();
		this->error();
		break;
	case 3:
		this->error();
		break;		
	default:
		this->insignificant();
		break;
	}
}
