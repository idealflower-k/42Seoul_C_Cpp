/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 21:05:11 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 21:06:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "Character.h"

class Character : public ICharacter {

	private:
		std::string	name;
	
	public:
		Character();
		Character(const Character& origin);
		
		Character& operator=(const Character& origin);

		std::string const&	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, Character& target);

		~Character();
};

#endif
