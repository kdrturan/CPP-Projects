#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main() {
	std::cout << "\n--- Point / bsp tests ---" << std::endl;

	Point aP(0.0f, 0.0f);
	Point bP(10.0f, 0.0f);
	Point cP(0.0f, 10.0f);

	Point inside(1.0f, 1.0f);
	Point outside(10.0f, 10.0f);
	Point edge(0.0f, 0.0f);
	Point border(5.0f, 0.0f); 

	std::cout << "Triangle points: A(0,0) B(10,0) C(0,10)" << std::endl;
	std::cout << "Point (1,1) inside? " << bsp(aP, bP, cP, inside) << std::endl;
	std::cout << "Point (10,10) inside? " << bsp(aP, bP, cP, outside) << std::endl;
	std::cout << "Point (0,0) inside? (vertex) " << bsp(aP, bP, cP, edge) << std::endl;
	std::cout << "Point (5,0) inside? (edge) " << bsp(aP, bP, cP, border) << std::endl;

	return 0;
}