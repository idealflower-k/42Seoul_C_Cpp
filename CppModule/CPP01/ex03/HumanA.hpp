/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:40:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 16:58:30 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {

	private :
		Weapon&		weapon_a;
		std::string	name;

	public :
		HumanA(std::string _name, Weapon& _weapon);
		void	attack(void) const;
};

#endif
