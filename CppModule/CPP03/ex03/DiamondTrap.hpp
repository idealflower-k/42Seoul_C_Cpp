/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:18:39 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 17:12:34 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_HPP
# define DIAMOND_HPP

#include "DiamondTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string name;

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
