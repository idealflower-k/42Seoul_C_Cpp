/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:17:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 16:22:14 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include "AAnimal.h"

class AAnimal {

	protected:
		std::string	type;
	
	public:
		AAnimal();
		AAnimal(std::string _type);
		AAnimal(const AAnimal& origin);

		AAnimal&			operator=(const AAnimal& origin);

		virtual void		makeSound(void) const = 0;
		virtual std::string	getType() const;

		virtual ~AAnimal();
};

#endif
