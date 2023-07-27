/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:06:35 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/27 12:48:19 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	try {
		ScalarConverter::convert(av[1]);
	} catch (std::exception& e) {
		std::cerr << "Exception!!: " << e.what();
	}
	return (0);
}
