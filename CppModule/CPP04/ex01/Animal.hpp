/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:17:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 22:30:56 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	protected:
		std::string	type;
	
	public:
		Animal();
		Animal(std::string _type);
		Animal(const Animal& origin);

		Animal&				operator=(const Animal& origin);

		virtual void		makeSound(void) const;
		virtual std::string	getType() const;

		virtual ~Animal();
};

#endif
