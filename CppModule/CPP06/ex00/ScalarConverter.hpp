/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/27 13:18:06 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <exception>
#include <iomanip>
#include <cctype>
#include <climits>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& origin);
		ScalarConverter&	operator=(const ScalarConverter& origin);
		~ScalarConverter();

		static bool			validCheckData(const std::string& data);
		static void			convertChar(const std::string& data);
		static void			convertInt(const std::string& data);
		static void			convertFloat(const std::string& data);
		static void			convertDouble(const std::string& data);

	public:
		static void	convert(const std::string& data);

		class ScalarValidError : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif