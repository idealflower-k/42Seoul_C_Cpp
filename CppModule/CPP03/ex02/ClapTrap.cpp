/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:21:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 20:12:00 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

const unsigned int ClapTrap::init_clap_hit = 10;
const unsigned int ClapTrap::init_clap_energy = 10;
const unsigned int ClapTrap::init_clap_attack = 0;

ClapTrap::ClapTrap()
	: name("default"), hit_points(init_clap_hit), energy_points(init_clap_energy), attack_damage(init_clap_attack) {
		std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
	: name(_name), hit_points(init_clap_hit), energy_points(init_clap_energy), attack_damage(init_clap_attack) {
		std::cout << "_name ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name, unsigned int hit, unsigned int energy, unsigned int attack)
	: name(_name), hit_points(hit), energy_points(energy), attack_damage(attack) {
	std::cout << "_name ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& origin)
	: name(origin.name), hit_points(origin.hit_points), energy_points(origin.energy_points), attack_damage(origin.attack_damage) {
		std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin) {

	std::cout << "ClapTrap Copy assignment operator called" << std::endl;

	if (this != &origin) {
		this->name = origin.name;
		this->hit_points = origin.hit_points;
		this->energy_points = origin.energy_points;
		this->attack_damage = origin.attack_damage;
	}

	return (*this);
}

void	ClapTrap::attack(const std::string& target) {

	if (this->energy_hit_point_check()) {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "ClapTrap " << this->name << " doesn't have energy or hit_points! " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (this->hit_points == 0) {
		std::cout << "ClapTrap " << this->name << " can't takes damage!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;

	if (this->hit_points < amount)
		this->hit_points = 0;
	else
		this->hit_points -= amount;

	std::cout << "    -> ClapTrap " << this->name << " have " << this->hit_points << " hit_points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->energy_hit_point_check()) {
		std::cout << "ClapTrap " << this->name << " repaired " << amount << std::endl;
		this->hit_points += amount;
		std::cout << "    -> ClapTrap " << this->name << " have " << this->hit_points << " hit_points" << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "ClapTrap " << this->name << " doesn't have energy or hit_points! " << std::endl;
}

bool	ClapTrap::energy_hit_point_check(void) {

	if (this->hit_points == 0 || this->energy_points == 0)
		return (false);
	return (true);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}
