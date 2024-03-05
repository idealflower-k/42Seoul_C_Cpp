#include "Fixed.h"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() : fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
	: fixed_point_num(num << fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f_num)
	: fixed_point_num(static_cast<int>(roundf(f_num * (1 << fractional_bits)))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin) 
	: fixed_point_num(origin.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin) {
		this->setRawBits(origin.getRawBits());
	}
	return (*this);
}

float	Fixed::toFloat(void) const {
	return (this->fixed_point_num / static_cast<float>(1 << fractional_bits));
}

int	Fixed::toInt(void) const {
	return (this->fixed_point_num >> fractional_bits);
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_num);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawbits member function called" << std::endl;
	this->fixed_point_num = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
