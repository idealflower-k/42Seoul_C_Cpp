/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:52:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 21:04:18 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.h"

ICharacter::ICharacter() {
	std::cout << "[ICharacter] Default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter& origin)
	: ICharacter(origin) {

	std::cout << "[ICharacter] Copy constructor called" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& origin) {
	
	std::cout << "[ICharacter] Copy assignment called" << std::endl;
	
	if (this != &origin) {}

	return (*this);
}

ICharacter::~ICharacter() {
	std::cout << "[ICharacter] Destructor called" << std::endl;
}
