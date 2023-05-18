/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:58:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/18 18:26:40 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"

int	main(void) {
	Point point1(2.2f, 5.1f);
	Point point2;
	Point point3(point1);

	std::cout << point1.getX() << std::endl;
	std::cout << point1.getY() << std::endl;

	std::cout << point2.getX() << std::endl;
	std::cout << point2.getY() << std::endl;
	
	std::cout << point3.getX() << std::endl;
	std::cout << point3.getY() << std::endl;
	
	point2 = point1;
	std::cout << point2.getX() << std::endl;
	std::cout << point2.getY() << std::endl;
}