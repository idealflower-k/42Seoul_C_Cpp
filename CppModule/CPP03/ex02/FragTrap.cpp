/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:26:26 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 20:12:04 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

const unsigned int	FragTrap::init_frag_hit = 100;
const unsigned int	FragTrap::init_frag_energy = 100;
const unsigned int	FragTrap::init_frag_attack = 30;

FragTrap::FragTrap()
	: ClapTrap("\0", init_frag_hit, init_frag_energy, init_frag_attack) {

	std::cout << "default FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string _name)
	: ClapTrap(_name, init_frag_hit, init_frag_energy, init_frag_attack) {

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
