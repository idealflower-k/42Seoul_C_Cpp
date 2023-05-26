/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:58:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 15:33:15 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongCat.h"

class WrongCat : public WrongAnimal {

	private:
		Brain*	wc_brain;
	
	public:
		WrongCat();
		WrongCat(const WrongCat& origin);

		WrongCat&	operator=(const WrongCat& origin);

		void		makeSound(void) const;
		std::string	getType(void) const;

		~WrongCat();
};

#endif
