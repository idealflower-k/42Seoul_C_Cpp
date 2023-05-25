/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:11:53 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/25 14:31:43 by sanghwal         ###   ########seoul.kr  */
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

		static const unsigned int	init_clap_hit;
		static const unsigned int	init_clap_energy;
		static const unsigned int	init_clap_attack;

	public:
		ClapTrap();
		ClapTrap(std::string _name);
		ClapTrap(std::string _name, unsigned int hit, unsigned int energy, unsigned int attack);
		ClapTrap(const ClapTrap& origin);

		ClapTrap&	operator=(const ClapTrap& origin);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		bool		energy_hit_point_check(void);

		~ClapTrap();
};


#endif
