/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:58:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 22:25:05 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {

	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& origin)
	: WrongAnimal(origin.type) {

	std::cout << "[WrongCat] Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& origin) {
	
	std::cout << "[WrongCat] Copy assignment called" << std::endl;

	if (this != &origin)
		WrongAnimal::operator=(origin);
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "[WrongCat] Meow~" << std::endl;
}

std::string	WrongCat::getType(void) const {
	std::cout << "[WrongCat] getType called" << std::endl;
	return (this->type);
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] Destructor called" << std::endl;
}
