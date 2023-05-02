/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:17:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/02 14:51:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"

HumanA::HumanA(std::string _name, Weapon& _weapon)
	: weapon_a(_weapon), name(_name) {}

void	HumanA::attack() const {
	std::cout << "HumanA attack : " << this->weapon_a.getType() << std::endl;
}
