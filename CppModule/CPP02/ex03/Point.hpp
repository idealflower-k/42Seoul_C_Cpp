/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:49:24 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/17 20:34:42 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

class Point {

	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float _fixed_num1, const float fixed_num2);
		Point(const Point& origin);
		Point& operator=(const Point& origin);

		
		~Point();
};

#endif
