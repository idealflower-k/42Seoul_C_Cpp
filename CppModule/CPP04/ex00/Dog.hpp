/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:42:12 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 22:20:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog& origin);
	
		Dog&		operator=(const Dog& origin);

		void		makeSound(void) const;
		std::string	getType(void) const;

		~Dog();
};

#endif
