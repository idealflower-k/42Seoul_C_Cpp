/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/26 16:16:51 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& origin) {(void)origin;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& origin) {
	(void)origin;
	return (*this);
}

const char*	ScalarConverter::ScalarValidError::what() const throw() {
	return("Can't convert!!!\n");
}

bool	ScalarConverter::validCheckData(const std::string& data) {
	char*	pEnd;

	std::strtod(data.c_str(), &pEnd);

	if ((data.length() == 1 && std::isalpha(*data.c_str()))
		|| (*pEnd == '\0' && !data.empty())
		|| (*pEnd == 'f' && std::strlen(pEnd) == 1))
		return (true);
	else
		return (false);
}

void	ScalarConverter::convertChar(const std::string& data) {
	const double	dataDouble = std::strtod(data.c_str(), NULL);

	std::cout << "char: ";
	if ((data.length() == 1 && std::isalpha(*data.c_str())))
		std::cout << '\'' << data << '\'' << "\n";
	else if (dataDouble - static_cast<int>(dataDouble) == 0 && dataDouble >= 0 && dataDouble <= 255) {
		if (dataDouble >= 32 && dataDouble <= 127)
			std::cout << '\'' << static_cast<char>(dataDouble) << '\'' << "\n";
		else
			std::cout << "Non displayable\n";
	}
	else
		std::cout << "impossible\n";
}

void	ScalarConverter::convertInt(const std::string& data) {
	const double	dataDouble = std::strtod(data.c_str(), NULL);

	std::cout << "int: ";
	if ((data.length() == 1 && std::isalpha(*data.c_str()))) {
		std::cout << static_cast<int>(*data.c_str()) << "\n";
	}
	else if (dataDouble >= INT_MIN && dataDouble <= INT_MAX) {
		std::cout << static_cast<int>(dataDouble) << "\n";
	}
	else
		std::cout << "impossible\n";
}

void	ScalarConverter::convertFloat(const std::string& data) {
	const double	dataDouble = std::strtod(data.c_str(), NULL);


	std::cout << "float: " << std::showpoint << std::setprecision(4);
	if ((data.length() == 1 && std::isalpha(*data.c_str())))
		std::cout << static_cast<float>(*data.c_str());
	else
		std::cout << static_cast<float>(dataDouble);
	std::cout << "f\n";
}

void	ScalarConverter::convertDouble(const std::string& data) {
	const double	dataDouble = std::strtod(data.c_str(), NULL);

	std::cout << "double: ";
	if ((data.length() == 1 && std::isalpha(*data.c_str())))
		std::cout << static_cast<double>(*data.c_str());
	else
		std::cout << static_cast<double>(dataDouble);
	std::cout << "\n";
}

void	ScalarConverter::convert(const std::string& data) {
	if (!ScalarConverter::validCheckData(data))
		throw ScalarConverter::ScalarValidError();

	ScalarConverter::convertChar(data);
	ScalarConverter::convertInt(data);
	ScalarConverter::convertFloat(data);
	ScalarConverter::convertDouble(data);
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "[ScalarConverter] Destructor called\n";
}
