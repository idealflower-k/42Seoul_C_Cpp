/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:45:55 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 21:04:24 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "ICharacter.h"

class ICharacter {

	public:
		ICharacter();
		ICharacter(const ICharacter& origin);
		
		ICharacter& operator=(const ICharacter& origin);

		virtual std::string const& getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;

		virtual ~ICharacter();
};

#endif
