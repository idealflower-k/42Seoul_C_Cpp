/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:19:59 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 22:43:45 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
	: type("\0") {

		std::cout << "[AAnimal] Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string _type)
	: type(_type) {

		std::cout << "[AAnimal] _type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& origin)
	: type(origin.type) {
		
		std::cout << "[AAnimal] Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& origin) {
	
	std::cout << "[Aniaml] assignment constructor called" << std:: endl;
	
	if (this != &origin) {
		this->type = origin.type;
	}
	return (*this);
}

std::string	AAnimal::getType(void) const{
	std::cout << "[AAnimal] getType called" << std::endl;
	return (this->type);
}

AAnimal::~AAnimal() {
	std::cout << "[AAnimal] Destructor called" << std::endl;
}
