/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:11:25 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/24 20:10:55 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "FragTrap.h"

class FragTrap : public ClapTrap {

	protected:
		static const unsigned int	init_frag_hit;
		static const unsigned int	init_frag_energy;
		static const unsigned int	init_frag_attack;

	public:
		FragTrap();
		FragTrap(std::string _name);
		FragTrap(const FragTrap& origin);

		FragTrap&	operator=(const FragTrap& origin);

		void		highFivesGuys(void);

		~FragTrap();
};

#endif
