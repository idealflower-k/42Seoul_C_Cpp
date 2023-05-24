/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:19:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 18:04:32 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.h"

DiamondTrap::DiamondTrap()
	: ClapTrap("_clap_name", 100, 50, 30), ScavTrap(), FragTrap() {
	std::cout << "Default DiamondTrap constructor called" << std::endl;

	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(std::string _name)
	: ClapTrap(_name + "_clap_name", 100, 50, 30), ScavTrap(_name), FragTrap(_name), name(_name) {

	std::cout << "_name DiamondTrap constructor called" <<std::endl;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& origin)
	: ClapTrap(origin.name + "_clap_name"), ScavTrap(origin.name), FragTrap(origin.name), name(origin.name) {

	std::cout << "DiamondTrap Copy constructor called" << std::endl;

	this->hit_points = origin.hit_points;
	this->energy_points = origin.energy_points;
	this->attack_damage = origin.attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origin) {

	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;

	if (this != &origin) {
		this->name = origin.name;
		this->hit_points = origin.hit_points;
		this->energy_points = origin.energy_points;
		this->attack_damage = origin.attack_damage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
	std::cout << "diamonTrap energy: " << this->energy_points << std::endl;
}

void	DiamondTrap::WhoAmI(void) {
	std::cout << "DiamondTrap name : " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}