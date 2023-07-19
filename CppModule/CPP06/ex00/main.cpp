/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:06:35 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/19 19:17:17 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char** av) {

	if (ac != 2) {
		return (1);
	}
	try {
		char c = std::strtod(av[1], NULL);
		std::cout << "char: " << c << "\n";
		int i = std::strtod(av[1], NULL);
		std::cout << "int: " << i << "\n";
		float af = std::strtof(av[1], NULL);
		std::cout << "float: " << af << "\n";
		double ad = std::strtod(av[1], NULL);
		std::cout << "double: " << ad << "\n";
	} catch (std::exception& e) {
		std::cerr << "error" << e.what();
	}
	return (0);
}
