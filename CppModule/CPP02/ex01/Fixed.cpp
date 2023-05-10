/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:22:49 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/10 20:52:09 by sanghwal         ###   ########seoul.kr  */
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
	this->fixed_point_num = static_cast<int>(roundf(f_num * 256)); // int형으로 명시적 형변환 해준다.
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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
