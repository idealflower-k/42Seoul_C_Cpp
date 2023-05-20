/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:29:41 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/20 23:23:59 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() : fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& origin) {
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(origin.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& origin) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &origin) {
		this->setRawBits(origin.getRawBits());
	}
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_num);
}

void	Fixed::setRawBits(int const raw) {
	this->fixed_point_num = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
