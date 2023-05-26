/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:39:16 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 20:46:15 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "AMateria.h"

class AMateria {

	protected:
		std::string	_type;
	
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& origin);

		AMateria&			operator=(const AMateria& origin);

		std::string const&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);

		virtual ~AMateria();
};

#endif
