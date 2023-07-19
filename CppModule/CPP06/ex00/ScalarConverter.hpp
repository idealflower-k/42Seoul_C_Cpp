/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/19 19:10:19 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& origin);

		ScalarConverter&	operator=(const ScalarConverter& origin);

		void	convert(const char* data);

		~ScalarConverter();
};

#endif