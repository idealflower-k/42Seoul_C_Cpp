/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:43:55 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/19 21:18:40 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

// 3 좌표가 삼각형이 가능한지 확인한다.
// 3 좌표의 넓이를 구한다.
// 점과 2개의 좌표의 넓이를 구한다. 총 3개
	// 넓이가 0이면 점은 꼭지점 혹은 면에 있는 상태이다.
// 3개의 삼각형 넓이와 큰삼각형의 넓이는 같아야한다.

#define X 0
#define Y 1

static float	triangleArea(const Point& p1, const Point& p2, const Point& p3) {

	Fixed	p1_cord[2] = {p1.getX(), p1.getY()};
	Fixed	p2_cord[2] = {p2.getX(), p2.getY()};
	Fixed	p3_cord[2] = {p3.getX(), p3.getY()};

	float	a = (p1_cord[X] * p2_cord[Y]) + (p2_cord[X] * p3_cord[Y]) + (p3_cord[X] * p1_cord[Y]);
	if (a < 0)
		a = -a;
	float	b = (p2_cord[X] * p1_cord[Y]) + (p3_cord[X] * p2_cord[Y]) + (p1_cord[X] * p3_cord[Y]);
	if (b < 0)
		b = -b;
	float	area = (a - b) / 2.0f;
	if (area < 0)
		area = -area;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

	float	big_tri = triangleArea(a, b, c);
	float	tri1 = triangleArea(point, a, b);
	float	tri2 = triangleArea(point, a, c);
	float	tri3 = triangleArea(point, b, c);
	
	std::cout << "big: " << big_tri << std::endl;
	std::cout << "tri1: " << tri1 << std::endl;
	std::cout << "tri2: " << tri2 << std::endl;
	std::cout << "tri3: " << tri3 << std::endl;

	if (tri1 == 0.0f || tri2 == 0.0f || tri3 == 0.0f)
		return (false);
	if (big_tri == (tri1 + tri2 + tri3))
		return (true);
	return (false);
}
