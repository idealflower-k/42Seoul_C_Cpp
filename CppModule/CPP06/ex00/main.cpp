/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:06:35 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/21 20:32:49 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include "ScalarConverter.hpp"

// int main(int ac, char **av)
// {

// 	if (ac != 2)
// 	{
// 		return (1);
// 	}
// 	const std::string data = av[1];
// 	char *pEnd;
// 	double temp = std::strtod(data.c_str(), &pEnd);
// 	std::cout << data << "\n";
// 	if (*pEnd == '\0' && !data.empty())
// 	{
// 		std::cout << "pEnd is null\n";
// 	}
// 	else
// 	{
// 		std::cerr << "pEnd is " << pEnd << "\n";
// 		return (1);
// 	}

// 	if (temp - static_cast<int>(temp) < std::numeric_limits<float>::epsilon())
// 	{
// 		char c = static_cast<char>(temp);
// 		std::cout << "char: " << c << "\n";
// 	}
// 	else
// 		std::cout << "char: "
// 				  << "non displayable\n";
// 	int i = static_cast<int>(temp);
// 	std::cout << "int: " << i << "\n";
// 	float af = static_cast<float>(temp);
// 	// std::cout << std::fixed;
// 	std::cout << "float: " << std::showpoint << std::setprecision(15) << af << "f\n";
// 	double ad = static_cast<double>(temp);
// 	std::cout << "double: " << ad << "\n";

// 	return (0);
// }

int main(int ac, char **av)
{

	if (ac != 2)
		return (1);
	
	try {
		ScalarConverter::convert(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what();
	}
	return (0);
}
