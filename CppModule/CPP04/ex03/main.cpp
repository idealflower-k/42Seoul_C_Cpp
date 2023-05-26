/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:41:05 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/26 20:44:19 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"
#include "Cure.h"

int main(void) {
	AMateria* a = new Ice();
	AMateria* b = new Ice();

	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;

	AMateria* c = a->clone();

	std::cout << c->getType() << std::endl;
}
