/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:26:26 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 18:03:20 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

FragTrap::FragTrap()
	: ClapTrap("\0", 100, 100, 30) {

	std::cout << "default FragTrap constructor called" << std::endl;

	// this->hit_points = 100;
	// this->energy_points = 100;
	// this->attack_damage = 30;
}

FragTrap::FragTrap(std::string _name)
	: ClapTrap(_name, 100, 100, 30) {

	std::cout << "_name FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& origin)
	: ClapTrap(origin.name) {
	std::cout << "FragTrap Copy constructor called" << std::endl;

	this->hit_points = origin.hit_points;
	this->energy_points = origin.energy_points;
	this->attack_damage = origin.attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap& origin) {
	std::cout << "FraTrap Copy assignment operator called" << std::endl;

	if (this != &origin) {
		this->name = origin.name;
		this->hit_points = origin.hit_points;
		this->energy_points = origin.energy_points;
		this->attack_damage = origin.attack_damage;
	}
	return (*this);
}

// void	FragTrap::attack(const std::string& target) {

// 	if (this->energy_hit_point_check()) {
// 		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
// 		this->energy_points -= 1;
// 	}
// 	else
// 		std::cout << "FragTrap " << this->name << " doesn't have energy or hit_points!" << std::endl;
// }

void	FragTrap::highFivesGuys(void) {

	if (this->energy_hit_point_check()) {
		std::cout << "FragTrap " << this->name << " Let's highfive!" << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "FragTrap " << this->name << " doesn't have energy or hit_points!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}
