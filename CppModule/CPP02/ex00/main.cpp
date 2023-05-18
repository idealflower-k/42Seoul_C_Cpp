/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:42:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/18 14:28:29 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"

int	main(void) {

	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	std::cout << a.getRawBits()	<< std::endl;
	std::cout << b.getRawBits()	<< std::endl;
	std::cout << c.getRawBits()	<< std::endl;

	a.setRawBits(42);
	std::cout << a.getRawBits() << std::endl;

	return (0);
}
