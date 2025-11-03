#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
 	void error( void );
	void insignificant( void );
	std::string	levels[4];
	int getLevelIndex(std::string level);
public:
	Harl();
	~Harl();
	void complain( std::string level );
};


#endif