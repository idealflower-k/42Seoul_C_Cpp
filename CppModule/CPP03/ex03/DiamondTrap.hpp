/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:18:39 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/25 14:51:26 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_HPP
# define DIAMOND_HPP

#include "DiamondTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string	name;

		static const unsigned int	init_diamond_hit;
		static const unsigned int	init_diamond_energy;
		static const unsigned int	init_diamond_attack;

	public:
		DiamondTrap();
		DiamondTrap(std::string _name);
		DiamondTrap(const DiamondTrap& origin);
		
		DiamondTrap&	operator=(const DiamondTrap& origin);
		
		void			attack(const std::string& target);
		void			WhoAmI(void);

		~DiamondTrap();
};

#endif
