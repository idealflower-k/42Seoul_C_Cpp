/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:23:13 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 13:52:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ScavTrap.h"

class ScavTrap : public ClapTrap {

	public:
		ScavTrap();
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap& origin);

		ScavTrap&	operator=(const ScavTrap& origin);

		void		attack(const std::string& target);
		void		guardGate(void);

		~ScavTrap();
};

#endif
