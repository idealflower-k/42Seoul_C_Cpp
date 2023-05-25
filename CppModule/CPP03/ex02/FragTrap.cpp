/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:26:26 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/25 14:47:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"

const unsigned int	FragTrap::init_frag_hit = 100;
const unsigned int	FragTrap::init_frag_energy = 100;
const unsigned int	FragTrap::init_frag_attack = 30;

FragTrap::FragTrap()
	: ClapTrap("default", init_frag_hit, init_frag_energy, init_frag_attack) {

	std::cout << "Default [FragTrap] constructor called" << std::endl;
}

FragTrap::FragTrap(std::string _name)
	: ClapTrap(_name, init_frag_hit, init_frag_energy, init_frag_attack) {

	std::cout << "_name [FragTrap] constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& origin)
	: ClapTrap(origin.name, origin.hit_points, origin.energy_points, origin.attack_damage) {

	std::cout << "[FragTrap] Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& origin) {
	std::cout << "[FraTrap] Copy assignment operator called" << std::endl;

	if (this != &origin)
		ClapTrap::operator=(origin);
	return (*this);
}

void	FragTrap::highFivesGuys(void) {

	if (this->energy_hit_point_check()) {
		std::cout << "[FragTrap] " << this->name << " Let's highfive!" << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "[FragTrap] " << this->name << " doesn't have energy or hit_points!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] " << this->name << " destructor called" << std::endl;
}
