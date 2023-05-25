/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:19:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/25 14:55:37 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

const unsigned int	DiamondTrap::init_diamond_hit = FragTrap::init_frag_hit;
const unsigned int	DiamondTrap::init_diamond_energy = ScavTrap::init_scav_energy;
const unsigned int	DiamondTrap::init_diamond_attack = FragTrap::init_frag_attack;

DiamondTrap::DiamondTrap()
	: ClapTrap("default_clap_name", init_diamond_hit, init_diamond_energy, init_diamond_attack), ScavTrap(), FragTrap(), name("default") {

	std::cout << "Default [DiamondTrap] constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name", init_diamond_hit, init_diamond_energy, init_diamond_attack), ScavTrap(_name), FragTrap(_name), name(_name) {

	std::cout << "_name [DiamondTrap] constructor called" <<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& origin)
	: ClapTrap(origin.name + "_clap_name", origin.hit_points, origin.energy_points, origin.attack_damage), ScavTrap(origin.name), FragTrap(origin.name), name(origin.name) {

	std::cout << "[DiamondTrap] Copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origin) {

	std::cout << "[DiamondTrap] Copy assignment operator called" << std::endl;

	if (this != &origin) {
		ClapTrap::operator=(origin);
		this->name = origin.name;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
	std::cout << "[DiamonTrap] energy: " << this->energy_points << std::endl;
}

void	DiamondTrap::WhoAmI(void) {
	std::cout << "[DiamondTrap] name : " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[DiamondTrap] " << this->name << " destructor called" << std::endl;
}