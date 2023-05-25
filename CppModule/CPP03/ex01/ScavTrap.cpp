/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:31:01 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/25 14:37:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

const unsigned int	ScavTrap::init_scav_hit = 100;
const unsigned int	ScavTrap::init_scav_energy = 50;
const unsigned int	ScavTrap::init_scav_attack = 20;

ScavTrap::ScavTrap()
	: ClapTrap("default", init_scav_hit, init_scav_energy, init_scav_attack) {

	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name)
	: ClapTrap(_name, init_scav_hit, init_scav_energy, init_scav_attack) {

	std::cout << "_name ScavTrap constructor called" <<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& origin)
	: ClapTrap(origin.name, origin.hit_points, origin.energy_points, origin.attack_damage) {

		std::cout << "ScavTrap Copy constructor called" << std::endl;
} 

ScavTrap& ScavTrap::operator=(const ScavTrap& origin) {

	std::cout << "ScavTrap Copy assignment operator called" << std::endl;

	if (this != &origin)
		ClapTrap::operator=(origin);
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
