/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:58:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/25 20:45:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongCat.h"

class WrongCat : public WrongAnimal {
	
	public:
		WrongCat();
		WrongCat(const WrongCat& origin);

		WrongCat&	operator=(const WrongCat& origin);

		void		makeSound(void) const;
		std::string	getType(void) const;

		~WrongCat();
};

#endif
