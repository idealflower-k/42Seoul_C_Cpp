/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:58:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/22 16:58:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include "Point.h"

// int	main(void) {

// 	Point point1(2.2f, 5.1f);
// 	Point point2;
// 	Point point3(point1);

// 	std::cout << "point1 : ";
// 	std::cout << point1.getX() << ", ";
// 	std::cout << point1.getY() << std::endl;

// 	std::cout << "point2 : ";
// 	std::cout << point2.getX() << ", ";
// 	std::cout << point2.getY() << std::endl;

// 	std::cout << "point3 : ";
// 	std::cout << point3.getX() << ", ";
// 	std::cout << point3.getY() << std::endl;
	
// 	point3 = point2;
// 	std::cout << "point3 = point2 : ";
// 	std::cout << point3.getX() << ", ";
// 	std::cout << point3.getY() << std::endl;

// 	std::cout << "point1 : ";
// 	std::cout << point1.getX() << ", ";
// 	std::cout << point1.getY() << std::endl;
// }

int	main(void) {
	Point	pointa(0.0f, 0.0f);
	Point	pointb(4.0f, 0.0f);
	Point	pointc(2.0f, 4.0f);
	Point	pointd(2.0f, 2.0f);

	
	Point	pointa2(1.0f, 1.0f);
	Point	pointb2(4.0f, 1.0f);
	Point	pointc2(2.0f, 4.0f);
	Point	pointd2(2.0f, 2.0f);


	Point	pointa3(0.0f, 0.0f);
	Point	pointb3(4.0f, 0.0f);
	Point	pointc3(2.0f, 4.0f);
	Point	pointd3(3.0f, 0.0f);


	Point	pointa4(0.0f, 0.0f);
	Point	pointb4(4.0f, 0.0f);
	Point	pointc4(2.0f, 4.0f);
	Point	pointd4(2.0f, 4.0f);


	bool	res = bsp(pointa, pointb, pointc, pointd);
	if (res == true)
		std::cout << "res1: " << "true" << std::endl;
	if (res == false)
		std::cout << "res1: " << "false" << std::endl;

	res = bsp(pointa2, pointb2, pointc2, pointd2);
	if (res == true)
		std::cout << "res2: " << "true" << std::endl;
	if (res == false)
		std::cout << "res2: " << "false" << std::endl;

	res = bsp(pointa3, pointb3, pointc3, pointd3);
	if (res == true)
		std::cout << "res3: " << "true" << std::endl;
	if (res == false)
		std::cout << "res3: " << "false" << std::endl;

	res = bsp(pointa4, pointb4, pointc4, pointd4);
	if (res == true)
		std::cout << "res4: " << "true" << std::endl;
	if (res == false)
		std::cout << "res4: " << "false" << std::endl;
}
