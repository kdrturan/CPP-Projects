#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::Fixed(const int intValue) {
	if (intValue > 8388607 || intValue < -8388608)
	{
		std::cerr << "Warning: Integer value " << intValue << " is out of range for Fixed point representation." << std::endl;
		return;
	}
	value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	if (floatValue > 8388607 || floatValue < -8388608)
	{
		std::cerr << "Warning: Integer value " << floatValue << " is out of range for Fixed point representation." << std::endl;
		return;
	}
	value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->value = other.value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const {
	return value;
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

float Fixed::toFloat(void) const {
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return value >> fractionalBits;
}


bool Fixed::operator>(const Fixed &other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->value != other.value;
}

Fixed &Fixed::operator++() {
    value += 1;  
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    value += 1;
    return temp;
}

Fixed &Fixed::operator--() {
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    value -= 1;
    return temp;
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.toFloat() == 0.0f) {
		std::cerr << "Error: Division by zero in Fixed::operator/. Returning 0." << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

void Fixed::absFixed()  {
	if (*this < Fixed(0)) {
		this->setRawBits(-this->getRawBits());
	}
}