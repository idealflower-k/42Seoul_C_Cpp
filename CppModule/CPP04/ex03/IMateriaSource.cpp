/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:59:20 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/27 18:51:40 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() {
	std::cout << "[IMateriaSource] Default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource& origin) {
	std:: cout << "[IMateriasourcr] Copy constructor called" << std::endl;
	(void)origin;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& origin) {
	
	std::cout << "[IMateriasource] Copy assignment called" << std::endl;
	
	if (this != &origin) {}

	return (*this);
}

IMateriaSource::~IMateriaSource() {
	std::cout << "[IMateriaSource] Destructor called" << std::endl;
}
