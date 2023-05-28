/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:32:01 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/28 17:54:38 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

	private:
		Brain*	c_brain;

	public:
		Cat();
		Cat(const Cat& origin);

		Cat&		operator=(const Cat& origin);

		void		makeSound(void) const;
		std::string	getType(void) const;
		Brain*		getBrain(void);
		void		addIdeas(const std::string& some);
		std::string	getIdeasIdx(int idx) const;

		~Cat();
};
#endif
