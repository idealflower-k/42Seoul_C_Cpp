/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:21:51 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 20:13:29 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"

AMateria::AMateria()
	: _type("\0") {

	std::cout << "[AMateria] Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
	: _type(type) {

	std::cout << "[AMateria] type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& origin)
	: _type(origin._type) {

	std::cout << "[AMateria] Copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& origin) {
	
	std::cout << "[AMateria] Copy assignment constructor called" << std:: endl;
	
	if (this != &origin)
		this->_type = origin._type;
	return (*this);
}

std::string const& AMateria::getType() const {
	return (this->_type);
}

AMateria::~AMateria() {
	std::cout << "[AMateria] Destructor called" << std::endl;
}
