#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include "Fixed.hpp"
class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float xValue, const float yValue);
	Point(const Point &other);
	~Point();	
	//Point &operator=(const Point &other);
	Fixed getX() const;
	Fixed getY() const;
};	

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed areaOfTriangle(Point const a, Point const b, Point const c);

#endif

