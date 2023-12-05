/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:40:46 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/05 22:02:40 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <math.h>

#include <cctype>
#include <climits>
#include <cmath>
#include <exception>
#include <iomanip>
#include <iostream>
#include <string>

#include "utils.hpp"

enum actualType { CHAR, INT, FLOAT, DOUBLE, NONE };

struct dataStruct {
  std::string dataStr;

  char charVal;
  std::string charStr;

  int intVal;
  std::string intStr;

  float floatVal;
  std::string floatStr;

  double doubleVal;
  std::string doubleStr;

  actualType type;

  dataStruct() : type(NONE) {}
};

class ScalarConverter {
 private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter& origin);
  ScalarConverter& operator=(const ScalarConverter& origin);

  static bool validCheckData(const std::string& targetStr);

  static void convertChar(dataStruct& dataStruct);
  static void convertInt(dataStruct& dataStruct);
  static void convertFloat(dataStruct& dataStruct);
  static void convertDouble(dataStruct& dataStruct);

  static void printChar(const dataStruct& dataStruct);
  static void printInt(const dataStruct& dataStruct);
  static void printFloat(const dataStruct& dataStruct);
  static void printDouble(const dataStruct& dataStruct);
  static void convertActualData(dataStruct& dataStruct,
                                const std::string& targetStr);
  static void convertOtherData(dataStruct& dataStruct);

 public:
  static void convert(const std::string& targetStr);

  class ScalarValidError : public std::exception {
   public:
    const char* what() const throw();
  };

  ~ScalarConverter();
};

#endif
