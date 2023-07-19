/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/19 19:10:31 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& origin) {(void)origin;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& origin) {
	(void)origin;
	return (*this);
}

void	ScalarConverter::convert(const char* data) {
	
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "[ScalarConverter] Destructor called\n";
}
