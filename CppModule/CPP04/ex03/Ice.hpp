/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:16:03 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 20:38:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "Ice.h"

class Ice : public AMateria {
	
	public:
		Ice();
		Ice(const Ice& origin);
		
		Ice& operator=(const Ice& origin);

		AMateria*	clone() const;
		void		use(ICharacter& target);

		~Ice();
};

#endif
