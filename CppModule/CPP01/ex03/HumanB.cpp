/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:26:22 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/02 14:51:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"

HumanB::HumanB(std::string _name)
	: name(_name) {}

void	HumanB::setWeapon(Weapon& _weapon) {
	this->weapon_b = &_weapon;
}

void	HumanB::attack() const {
	std::cout << "HumanB attack : " << this->weapon_b->getType() << std::endl;
}
