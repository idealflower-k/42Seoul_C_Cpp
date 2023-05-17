/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:37:36 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/17 15:15:48 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

Fixed::Fixed() : fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	this->fixed_point_num = num << this->fractional_bits;
}

Fixed::Fixed(const float f_num) {
	this->fixed_point_num = static_cast<int>(roundf(f_num * 256.0f)); // int형으로 명시적 형변환 해준다.
}

Fixed::Fixed(const Fixed& origin) {
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_num = origin.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin) {
		this->fixed_point_num = origin.getRawBits();
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
	// std::cout << "this:" << this->toFloat() << "  other:" << other.toFloat() << std::endl;
	return this->toFloat() * other.toFloat();
}

float	Fixed::operator/(const Fixed& other) {
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
	return (this->fixed_point_num / 256.0f);
}

int	Fixed::toInt(void) const {
	return (this->fixed_point_num >> this->fractional_bits);
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_num);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed_point_num = raw;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
	if (num1.toFloat() < num2.toFloat())
		return (num1);
	return (num2);
}

Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
	if (num1.toFloat() < num2.toFloat())
		return (const_cast<Fixed&>(num1));
	return (const_cast<Fixed&>(num2));
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	if (num1.toFloat() > num2.toFloat())
		return (num1);
	return (num2);
}

Fixed& Fixed::max(const Fixed& num1, const Fixed& num2) {
	if (num1.toFloat() > num2.toFloat())
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
