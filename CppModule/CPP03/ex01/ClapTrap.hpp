/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:11:53 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 13:55:27 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include "ClapTrap.h"

class ClapTrap {

	protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;

	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(const ClapTrap& origin);

		ClapTrap& operator=(const ClapTrap& origin);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		bool	energy_hit_point_check(void);

		~ClapTrap();
};

#endif
