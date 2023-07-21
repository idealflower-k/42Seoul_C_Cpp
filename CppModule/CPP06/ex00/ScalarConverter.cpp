/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/21 20:49:29 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& origin) {(void)origin;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& origin) {
	(void)origin;
	return (*this);
}

bool	ScalarConverter::validCheckData(const std::string& data) {
	char*	pEnd;

	std::strtod(data.c_str(), &pEnd);
	std::cout << "pEnd: " << *pEnd << "\n";
	if ((*pEnd == '\0' && !data.empty()) || (*pEnd == 'f' && std::strlen(pEnd) == 1))
		return (true);
	else
		return (false);
}

void	ScalarConverter::convertChar(const double& dataDouble) {
	std::cout << "char: ";
	if (dataDouble - static_cast<int>(dataDouble) == 0) {
		if (dataDouble >= 32 && dataDouble <= 127)
			std::cout << static_cast<char>(dataDouble) << "\n";
		else
			std::cout << "Non displayable\n";
	}
	else
		std::cout << "impossible\n";
}

void	ScalarConverter::convertInt(const double& dataDouble) {
	std::cout << "Int: ";
	if (dataDouble >= INT_MIN && dataDouble <= INT_MAX) {
		std::cout << static_cast<int>(dataDouble) << "\n";
	}
	else
		std::cout << "impossible\n";
}

void	ScalarConverter::convert(const std::string& data) {
	if (!ScalarConverter::validCheckData(data))
		throw std::runtime_error("error!\n");
		// throw ScalarConverter::ScalarValidError();

	const double	dataDouble = std::strtod(data.c_str(), NULL);

	ScalarConverter::convertChar(dataDouble);
	ScalarConverter::convertInt(dataDouble);
	// convertFloat(dataDouble);
	// convertDouble(dataDouble);
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "[ScalarConverter] Destructor called\n";
}
