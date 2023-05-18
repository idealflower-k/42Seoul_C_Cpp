/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:37:36 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/18 17:31:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "const int constructor called" << std::endl;
	this->fixed_point_num = num << fractional_bits;
}

Fixed::Fixed(const float f_num) {
	std::cout << "const float constructor called" << std::endl;
	this->fixed_point_num = static_cast<int>(roundf(f_num * (1 << fractional_bits)));
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

bool	Fixed::operator>(const Fixed& other) const {
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) const {
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (this->toFloat() != other.toFloat());
}

float	Fixed::operator+(const Fixed& other) {
	return (this->toFloat() + other.toFloat());
}

float	Fixed::operator-(const Fixed& other) {
	return (this->toFloat() - other.toFloat());
}

float	Fixed::operator*(const Fixed& other) {
	return this->toFloat() * other.toFloat();
}

/**
 * @brief Division operator for Fixed class
 * @param other The divisor
 * @throws std::invalid_argument if the divisor is zero
 * @return The result of the division as a float
 */
float	Fixed::operator/(const Fixed& other) {
	if (other.toFloat() == 0.0f)
		throw std::invalid_argument("Division by Zero");
	return (this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++(void) {
	++(this->fixed_point_num);
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed result(*this);
	++(this->fixed_point_num);
	return (result);
}

Fixed&	Fixed::operator--(void) {
	--(this->fixed_point_num);
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed result(*this);
	--(this->fixed_point_num);
	return (result);
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
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point_num = raw;
}

/**
 * Returns the minimum value between num1 and num2. 
 * If both are equal, num1 is returned.
 *
 * @param num1 - First value to compare
 * @param num2 - Second value to compare
 * @return The smaller value between num1 and num2. If they're equal, num1 is returned.
 */
Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
	if (num1.toFloat() <= num2.toFloat())
		return (num1);
	return (num2);
}

/**
 * Returns the minimum value between num1 and num2. 
 * If both are equal, num1 is returned.
 *
 * @param num1 - First value to compare
 * @param num2 - Second value to compare
 * @return The smaller value between num1 and num2. If they're equal, num1 is returned.
 */
Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
	if (num1.toFloat() <= num2.toFloat())
		return (const_cast<Fixed&>(num1));
	return (const_cast<Fixed&>(num2));
}

/**
 * Returns the maximum value between num1 and num2.
 * If both are equal, num1 is returned.
 *
 * @param num1 - First value to compare
 * @param num2 - Second value to compare
 * @return The larger value between num1 and num2. If they're equal, num1 is returned.
 */
Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	if (num1.toFloat() >= num2.toFloat())
		return (num1);
	return (num2);
}

/**
 * Returns the maximum value between num1 and num2.
 * If both are equal, num1 is returned.
 *
 * @param num1 - First value to compare
 * @param num2 - Second value to compare
 * @return The larger value between num1 and num2. If they're equal, num1 is returned.
 */
Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
	if (num1.toFloat() >= num2.toFloat())
		return (const_cast<Fixed&>(num1));
	return (const_cast<Fixed&>(num2));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
