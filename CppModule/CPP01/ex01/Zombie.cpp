/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:41:52 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/04 13:43:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() {}

Zombie::Zombie(std::string _name) {
	this->name = _name;
}

void	Zombie::announce() {
	std::cout << this->name << ":" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string _name) {
	this->name = _name;
}

Zombie::~Zombie() {
	std::cout << this->name << std::endl;
}
