/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/10 16:17:57 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& dataStr) {
  if (!ScalarConverter::validCheckData(dataStr))
    throw ScalarConverter::ScalarValidError();

  dataStruct dataStruct;

  ScalarConverter::convertActualData(dataStruct, dataStr);
  ScalarConverter::convertOtherData(dataStruct);
  ScalarConverter::printData(dataStruct);
}

bool ScalarConverter::validCheckData(const std::string& targetStr) {
  char* pEnd;

  if (std::isspace(targetStr[0])) return (false);

  std::strtod(targetStr.c_str(), &pEnd);
  if ((targetStr.length() == 1 && std::isalpha(*targetStr.c_str())) ||
      (*pEnd == '\0' && !targetStr.empty()) ||
      (*pEnd == 'f' && std::strlen(pEnd) == 1 &&
       targetStr.find('.') != std::string::npos) ||
      (targetStr.compare("nanf") == 0) || (targetStr.compare("inff") == 0) ||
      (targetStr.compare("+inff") == 0) || (targetStr.compare("-inff") == 0))
    return (true);
  else
    return (false);
}

void ScalarConverter::convertActualData(dataStruct& dataStruct,
                                        const std::string& dataStr) {
  char* pEnd;
  const double dataDouble = std::strtod(dataStr.c_str(), &pEnd);

  (void)dataDouble;
  dataStruct.dataStr = dataStr;

  if ((dataStr.length() == 1 && std::isalpha(*dataStr.c_str()))) {
    ScalarConverter::convertChar(dataStruct);
    dataStruct.type = CHAR;
  } else if (std::isdigit(*dataStr.c_str()) &&
             dataStr.find('.') == std::string::npos) {
    ScalarConverter::convertInt(dataStruct);
    dataStruct.type = INT;
  } else if (dataStr.find('.') != std::string::npos && *pEnd == 'f' &&
             std::strlen(pEnd) == 1) {
    ScalarConverter::convertFloat(dataStruct);
    dataStruct.type = FLOAT;
  } else {
    ScalarConverter::convertDouble(dataStruct);
    dataStruct.type = DOUBLE;
  }
}

void ScalarConverter::convertOtherData(dataStruct& dataStruct) {
  switch (dataStruct.type) {
    case CHAR:
      ScalarConverter::convertInt(dataStruct);
      ScalarConverter::convertFloat(dataStruct);
      ScalarConverter::convertDouble(dataStruct);
      break;
    case INT:
      ScalarConverter::convertChar(dataStruct);
      ScalarConverter::convertFloat(dataStruct);
      ScalarConverter::convertDouble(dataStruct);
      break;
    case FLOAT:
      ScalarConverter::convertChar(dataStruct);
      ScalarConverter::convertInt(dataStruct);
      ScalarConverter::convertDouble(dataStruct);
      break;
    case DOUBLE:
      ScalarConverter::convertChar(dataStruct);
      ScalarConverter::convertInt(dataStruct);
      ScalarConverter::convertFloat(dataStruct);
      break;
    default:
      break;
  }
}

void ScalarConverter::printData(const dataStruct& dataStruct) {
  std::cout << "char: " + dataStruct.charStr << std::endl;
  std::cout << "int: " + dataStruct.intStr << std::endl;
  std::cout << "float: ";
  std::cout << std::fixed << std::showpoint << std::setprecision(1);
  std::cout << dataStruct.floatVal << "f" << std::endl;
  std::cout << "double: " << dataStruct.doubleVal << std::endl;
}

void ScalarConverter::convertChar(dataStruct& dataStruct) {
  const double dataDouble = std::strtod(dataStruct.dataStr.c_str(), NULL);

  dataStruct.charVal = '\0';
  if ((dataStruct.dataStr.length() == 1 &&
       std::isalpha(*dataStruct.dataStr.c_str()))) {
    dataStruct.charVal = static_cast<char>(*dataStruct.dataStr.c_str());
    dataStruct.charStr = "\'" + std::string(1, dataStruct.charVal) + "\'";
  } else if (dataDouble - static_cast<int>(dataDouble) == 0 &&
             dataDouble >= 0 && dataDouble <= 255) {
    if (dataDouble >= 32 && dataDouble <= 127) {
      dataStruct.charVal = static_cast<char>(dataDouble);
      dataStruct.charStr = "\'" + std::string(1, dataStruct.charVal) + "\'";
    } else
      dataStruct.charStr = "Non displayable";
  } else
    dataStruct.charStr = "impossible";
}

void ScalarConverter::convertInt(dataStruct& dataStruct) {
  const double dataDouble = std::strtod(dataStruct.dataStr.c_str(), NULL);

  dataStruct.intVal = 0;

  if ((dataStruct.dataStr.length() == 1 &&
       std::isalpha(*dataStruct.dataStr.c_str())) ||
      (dataDouble >= INT_MIN && dataDouble <= INT_MAX)) {
    dataStruct.intVal = static_cast<int>(dataDouble);
    dataStruct.intStr = utils::intToString(dataStruct.intVal);
  } else
    dataStruct.intStr = "impossible";
}

void ScalarConverter::convertFloat(dataStruct& dataStruct) {
  const double dataDouble = std::strtod(dataStruct.dataStr.c_str(), NULL);

  if ((dataStruct.dataStr.length() == 1 &&
       std::isalpha(*dataStruct.dataStr.c_str()))) {
    dataStruct.floatVal = static_cast<float>(*dataStruct.dataStr.c_str());
  } else
    dataStruct.floatVal = static_cast<float>(dataDouble);
}

void ScalarConverter::convertDouble(dataStruct& dataStruct) {
  const double dataDouble = std::strtod(dataStruct.dataStr.c_str(), NULL);

  if ((dataStruct.dataStr.length() == 1 &&
       std::isalpha(*dataStruct.dataStr.c_str()))) {
    dataStruct.doubleVal = static_cast<double>(*dataStruct.dataStr.c_str());
  } else
    dataStruct.doubleVal = dataDouble;
}

const char* ScalarConverter::ScalarValidError::what() const throw() {
  return ("Can't convert!!!\n");
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& origin) {
  (void)origin;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& origin) {
  (void)origin;
  return (*this);
}

ScalarConverter::~ScalarConverter() {}
