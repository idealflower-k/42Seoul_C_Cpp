/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/21 20:28:32 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>

class ScalarConverter {
	private:
		ScalarConverter();
		static bool	validCheckData(const std::string& data);
		static void	convertChar(const double& dataDouble);
		static void	convertInt(const double& dataDouble);
		// static void	convertFloat(const double& dataDouble);
		// static void	convertDouble(const double& dataDouble);

	public:
		ScalarConverter(const ScalarConverter& origin);

		ScalarConverter&	operator=(const ScalarConverter& origin);

		static void	convert(const std::string& data);

		~ScalarConverter();

		// class ScalarValidError : public std::exception {
		// 	public:
		// 		const char* what() const throw();
		// };
		// class ScalarImpossible : public std::exception {
		// 	public:
		// 		const char* what() const throw();
		// };
		// class NonDisplayable : public std::exception {
		// 	public:
		// 		const char* what() const throw();
		// };
};

#endif