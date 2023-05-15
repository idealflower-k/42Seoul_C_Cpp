/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:37:36 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/15 18:48:53 by sanghwal         ###   ########seoul.kr  */
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
	return (this->toFloat() * other.toFloat());
}

float	Fixed::operator/(const Fixed& other) {
	return (this->toFloat() / other.toFloat());
}

Fixed&	Fixed::operator++(void) {
	this->fixed_point_num += static_cast<int>(roundf(this->toFloat() * (1 << this->fractional_bits)));
	return (*this);
}

Fixed&	Fixed::operator++(int) {
	Fixed result(*this);
	this->fixed_point_num += static_cast<int>(roundf(this->toFloat() * (1 << this->fractional_bits)));
	return (result);
}

Fixed&	Fixed::operator--(void) {
	this->fixed_point_num -= static_cast<int>(roundf(this->toFloat() * (1 << this->fractional_bits)));
	return (*this);
}

Fixed&	Fixed::operator--(int) {
	Fixed result(*this);
	this->fixed_point_num -= static_cast<int>(roundf(this->toFloat() * (1 << this->fractional_bits)));
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

const Fixed& Fixed::min(int& fixed_num1, int& fixed_num2) {
	if (fixed_num1 < fixed_num2)
		return (fixed_num1);
	return (fixed_num2);
}

const Fixed& Fixed::min(const int& fixed_num1, const int& fixed_num2)
{
	if (fixed_num1 < fixed_num2)
		return (const_cast<int&>(fixed_num1));
	return (const_cast<int&>(fixed_num2));
}

const Fixed& Fixed::max(int& fixed_num1, int& fixed_num2) {
	if (fixed_num1 > fixed_num2)
		return (fixed_num1);
	return (fixed_num2);
}

const Fixed& Fixed::max(const int& fixed_num1, const int& fixed_num2) {
	if (fixed_num1 > fixed_num2)
		return (const_cast<int&>(fixed_num1));
	return (const_cast<int&>(fixed_num2));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
