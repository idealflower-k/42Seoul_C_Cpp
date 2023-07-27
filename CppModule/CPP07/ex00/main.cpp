/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:58:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/27 15:22:21 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <string>

struct test {
	int	data;
};

int	main(void) {
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << "\n";
	std::cout << "min(a, b) = " << ::min(a, b) << "\n";
	std::cout << "max(a, b) = " << ::max(a, b) << "\n";

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << "\n";
	std::cout << "min(c, d) = " << ::min(c, d) << "\n";
	std::cout << "max(c, d) = " << ::max(c, d) << "\n";

	const char *str1 = "abc";
	const char *str2 = "bbc";

	::swap(str1, str2);
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << "\n";
	std::cout << "min(str1, str2) = " << ::min(str1, str2) << "\n";
	std::cout << "max(str1, str2) = " << ::max(str1, str2) << "\n";

	double	d1 = 123.45;
	double	d2 = 123.46;

	::swap(d1, d2);
	std::cout << "d1 = " << d1 << ", d2 = " << d2 << "\n";
	std::cout << "min(d1, d2) = " << ::min(d1, d2) << "\n";
	std::cout << "max(d1, d2) = " << ::max(d1, d2) << "\n";

	test	test1 = {1};
	test	test2 = {2};

	::swap(test1, test2);
	std::cout << "test1 = " << test1.data << ", test2 = " << test2.data << "\n";
	std::cout << "min(test1, test2) = " << ::min(test1.data, test2.data) << "\n";
	std::cout << "max(test1, test2) = " << ::max(test1.data, test2.data) << "\n";

	return (0);
}
