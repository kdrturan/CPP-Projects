#include <string>
#include <iostream>

int main() {
	std::string name = "HI THIS IS BRAIN";
	std::string* stringPTR = &name;
	std::string& stringREF = name;

	std::cout << "Address of string variable: " << &name << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of string variable: " << name << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return 0;
}