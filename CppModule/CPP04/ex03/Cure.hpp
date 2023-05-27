/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:37:35 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 18:30:49 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure& origin);
		
		Cure& operator=(const Cure& origin);

		AMateria*	clone() const;
		void		use(ICharacter& target);

		~Cure();
};

#endif