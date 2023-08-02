/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/08/02 15:47:01 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <climits>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& origin);
  ScalarConverter& operator=(const ScalarConverter& origin);
  ~ScalarConverter();

  static bool validCheckData(const std::string& data);
  static void convertChar(const std::string& data);
  static void convertInt(const std::string& data);
  static void convertFloat(const std::string& data);
  static void convertDouble(const std::string& data);

 public:
  static void convert(const std::string& data);

  class ScalarValidError : public std::exception {
   public:
    const char* what() const throw();
  };
};

#endif
