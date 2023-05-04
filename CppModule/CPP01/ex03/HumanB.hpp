/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:06:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/04 13:44:57 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {
	private :
		Weapon*		weapon_b;
		std::string name;
	public :
		HumanB(std::string _name);
		void	setWeapon(Weapon& _weapon);
		void	attack() const;
};

#endif
