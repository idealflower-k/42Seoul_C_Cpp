/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:34:26 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 22:24:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat") {

	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& origin)
	: Animal(origin.type) {

	std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& origin) {
	
	std::cout << "[Cat] Copy assignment called" << std::endl;

	if (this != &origin)
		Animal::operator=(origin);
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "[Cat] Meow~" << std::endl;
}

std::string	Cat::getType(void) const{
	std::cout << "[Cat] getType called" << std::endl;
	return (this->type);
}

Cat::~Cat() {
	std::cout << "[Cat] Destructor called" << std::endl;
}