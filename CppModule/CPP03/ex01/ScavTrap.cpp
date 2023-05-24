/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:31:01 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 14:02:04 by sanghwal         ###   ########seoul.kr  */
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

ScavTrap::ScavTrap(const ScavTrap& origin)
	: ClapTrap(origin) {
		std::cout << "ScavTrap Copy constructor called" << std::endl;
} 

ScavTrap& ScavTrap::operator=(const ScavTrap& origin) {

	std::cout << "ScavTrap Copy assignment operator called" << std::endl;

	if (this != &origin) {
		this->name = origin.name;
		this->hit_points = origin.hit_points;
		this->energy_points = origin.energy_points;
		this->attack_damage = origin.attack_damage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {

	if (this->energy_hit_point_check()) {
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "ScavTrap " << this->name << " doesn't have energy or hit_points!" << std::endl;
}

void	ScavTrap::guardGate() {

	if (this->energy_hit_point_check()) {
		std::cout << "ScavTrap " << this->name << " now Gate Keeper mode" << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "ScavTrap " << this->name << " doesn't have energy or hit_points!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}