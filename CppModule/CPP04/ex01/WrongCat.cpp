/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:58:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 22:33:46 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {

	std::cout << "[WrongCat] Default constructor called" << std::endl;

	this->wc_brain = new Brain();
}

WrongCat::WrongCat(const WrongCat& origin)
	: WrongAnimal(origin.type) {

	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	this->wc_brain = origin.wc_brain;
}

WrongCat& WrongCat::operator=(const WrongCat& origin) {
	
	std::cout << "[WrongCat] Copy assignment called" << std::endl;

	if (this != &origin) {
		WrongAnimal::operator=(origin);
		this->wc_brain = origin.wc_brain;
	}
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
	// delete wc_brain;
}
