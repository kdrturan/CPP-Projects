#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

// Point &Point::operator=(const Point &other) {
// 	if (this != &other) {
// 		this->x = other.x;
// 		this->y = other.y;
// 	}
// 	return *this;
// }

Fixed Point::getX() const {
	return x;
}

Fixed Point::getY() const {
	return y;
}

Fixed areaOfTriangle(Point const a, Point const b, Point const c) {
	const Fixed ZERO(0);

	Fixed area = (a.getX() * (b.getY() - c.getY()) +
					b.getX() * (c.getY() - a.getY()) +
					c.getX() * (a.getY() - b.getY()));
	if (area < ZERO)
		area = ZERO - area;
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	const Fixed EPS(0.000001f);
	
	Fixed area_abc = areaOfTriangle(a, b, c);

	Fixed area_abp = areaOfTriangle(a, b, point);
	Fixed area_acp = areaOfTriangle(a, point, c);
	Fixed area_bcp = areaOfTriangle(point, b, c);

	Fixed sum = area_abp + area_acp + area_bcp;

	Fixed diff = area_abc - sum;
	diff.absFixed();

	if (diff > EPS)
		return false;

	if (area_abp <= EPS || area_acp <= EPS || area_bcp <= EPS)
		return false;

	return true;
}