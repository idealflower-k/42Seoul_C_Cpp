/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/06 19:59:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <math.h>

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

#include "utils.hpp"

enum actualType { CHAR, INT, FLOAT, DOUBLE };

struct dataStruct {
  std::string dataStr;

  char charVal;
  std::string charStr;

  int intVal;
  std::string intStr;

  float floatVal;

  double doubleVal;

  actualType type;

  dataStruct() : type(DOUBLE) {}
};

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& origin);
  ScalarConverter& operator=(const ScalarConverter& origin);

  static bool validCheckData(const std::string& targetStr);
  static void convertActualData(dataStruct& dataStruct,
                                const std::string& targetStr);
  static void convertOtherData(dataStruct& dataStruct);

  static void convertChar(dataStruct& dataStruct);
  static void convertInt(dataStruct& dataStruct);
  static void convertFloat(dataStruct& dataStruct);
  static void convertDouble(dataStruct& dataStruct);

  static void printData(const dataStruct& dataStruct);

  class ScalarValidError : public std::exception {
   public:
    const char* what() const throw();
  };

 public:
  static void convert(const std::string& targetStr);

  ~ScalarConverter();
};

#endif
