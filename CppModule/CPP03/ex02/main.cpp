/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:56:53 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 14:56:59 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

int	main(void) {

	ScavTrap	scav_1;
	ScavTrap	scav_2("scav_2");
	ScavTrap	scav_3("scav_3");
	FragTrap	frag_1("frag_1");
	FragTrap	frag_2("frag_2");

	scav_1.attack("target");
	scav_2.attack("scave_3");
	scav_3.takeDamage(20);

	scav_3.beRepaired(10);
	scav_3.attack("scav_2");
	scav_2.takeDamage(120);
	scav_2.beRepaired(10);
	
	scav_2.guardGate();

	ScavTrap scav_4 = scav_3;
	scav_4.takeDamage(10);
	scav_3.takeDamage(0);

	frag_1.attack("some");
	frag_1.takeDamage(0);
	frag_1.highFivesGuys();
	frag_2.highFivesGuys();
}
