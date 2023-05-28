/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:45:04 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/28 17:11:41 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
	: next_idx(0) {
	
	std::cout << "[Brain] Default constrctor called" << std::endl;
}

Brain::Brain(const Brain& origin)
	: next_idx(origin.next_idx) {
	
	std::cout << "[Brain] Copy constructor called" << std::endl;
	
	for  (int i = 0; i < 100; ++i)
		this->ideas[i] = origin.ideas[i];
}

Brain& Brain::operator=(const Brain& origin) {

	std::cout << "[Brain] assignment constructor called" << std:: endl;
	
	if (this != &origin) {
		for  (int i = 0; i < 100; ++i)
			this->ideas[i] = origin.ideas[i];
		this->next_idx = origin.next_idx;
	}
	return (*this);
}

void	Brain::addIdeas(const std::string& some) {

	if (next_idx < 100)
		this->ideas[next_idx++] = some;
	else
		std::cout << "[Brain] ideas is full" << std::endl;
}

std::string*	Brain::getIdeas(void) {
	return (this->ideas);
}

std::string	Brain::getIdeasIdx(int idx) const {

	if (idx >= 100)
		return ("Wrong idx value");
	return (this->ideas[idx]);
}

Brain::~Brain() {
	std::cout << "[Brain] Destructor called" << std::endl;
}
