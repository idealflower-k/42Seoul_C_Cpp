/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:21:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/23 20:11:36 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap()
	: name("default"), hit_points(10), energy_points(10), attack_damage(0) {
		std::cout << "Default constructor called" << std::endl;
	}

ClapTrap::ClapTrap(std::string _name)
	: name(_name), hit_points(10), energy_points(10), attack_damage(0) {
		std::cout << "_name constructor called" << std::endl;
	}

ClapTrap::ClapTrap(const ClapTrap& origin)
	: name(origin.name), hit_points(origin.hit_points), energy_points(origin.energy_points), attack_damage(origin.attack_damage) {
		std::cout << "Copy constructor called" << std::endl;
	}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &origin) {
		this->name = origin.name;
		this->hit_points = origin.hit_points;
		this->energy_points = origin.energy_points;
		this->attack_damage = origin.attack_damage;
	}

	return (*this);
}

void	ClapTrap::attack(const std::string& target) {

	if (this->energy_points == 0 || hit_points == 0)
		std::cout << "ClapTrap " << this->name << " doesn't have energy or hit_points! " << std::endl;
	else {
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {

	if (this->hit_points == 0) {
		std::cout << "ClapTrap " << this->name << " can't takes damage!" << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!" << std::endl;

	if (this->hit_points < amount) {
		this->hit_points = 0;
	}
	else {
		this->hit_points -= amount;
	}

	std::cout << "    -> ClapTrap " << this->name << " have " << this->hit_points << " hit_points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {

	if (this->energy_points == 0 || this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " doesn't have energy or hit_points! " << std::endl;
	else {
		std::cout << "ClapTrap " << this->name << " repaired " << amount << std::endl;
		this->hit_points += amount;
		std::cout << "    -> ClapTrap " << this->name << " have " << this->hit_points << " hit_points" << std::endl;
		this->energy_points -= 1;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}
