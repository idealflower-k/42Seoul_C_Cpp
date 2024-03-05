#include "Point.h"

Point::Point()
	: x(0), y(0) {}

Point::Point(const float _fixed_num1, const float _fixed_num2)
	: x(Fixed(_fixed_num1)), y(Fixed(_fixed_num2)) {}

Point::Point(const Point& origin)
	: x(origin.x), y(origin.y) {}

Point& Point::operator=(const Point& origin) {
	if (this != &origin) {
		const_cast<Fixed&>(this->x) = origin.getX();
		const_cast<Fixed&>(this->y) = origin.getY();
	}
	return (*this);
}

const Fixed& Point::getX() const {
	return (this->x);
}

const Fixed& Point::getY() const {
	return (this->y);
}

Point::~Point() {
	// std::cout << "Point Destructor called" << std::endl;
}
