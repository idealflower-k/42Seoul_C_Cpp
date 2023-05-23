/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:31:01 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/23 20:51:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

ScavTrap::ScavTrap()
	: ClapTrap() {
		std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name)
	: ClapTrap(_name) {
		std::cout << "_name ScavTrap constructor called" <<std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energy_points == 0 || this->hit_points == 0)
		std::cout << "ScavTrap " << this->name << " doesn't have energy or hit_points! " << std::endl;
	else {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points -= 1;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " now Gate Keeper mode" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}