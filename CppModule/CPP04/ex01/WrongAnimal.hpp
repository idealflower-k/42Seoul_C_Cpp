/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:50:42 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 15:37:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include "WrongAnimal.h"

class WrongAnimal {
	
	protected:
		std::string	type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string _type);
		WrongAnimal(const WrongAnimal& origin);

		WrongAnimal&	operator=(const WrongAnimal& origin);

		void			makeSound(void) const;
		std::string		getType(void) const;

		virtual ~WrongAnimal();
};

#endif
