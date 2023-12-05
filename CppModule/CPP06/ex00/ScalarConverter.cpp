/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:09 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/05 22:07:58 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const char* ScalarConverter::ScalarValidError::what() const throw() {
  return ("Can't convert!!!\n");
}

bool ScalarConverter::validCheckData(const std::string& targetStr) {
  char* pEnd;

  if (std::isspace(targetStr[0])) return (false);

  std::strtod(targetStr.c_str(), &pEnd);
  if ((targetStr.length() == 1 && std::isalpha(*targetStr.c_str())) ||
      (*pEnd == '\0' && !targetStr.empty()) ||
      (*pEnd == 'f' && std::strlen(pEnd) == 1))
    return (true);
  else
    return (false);
}

void ScalarConverter::printChar(const dataStruct& dataStruct) {
  std::cout << "char: " + dataStruct.charStr << std::endl;
}

void ScalarConverter::printInt(const dataStruct& dataStruct) {
  std::cout << "int: " + dataStruct.intStr << std::endl;
}

void ScalarConverter::printFloat(const dataStruct& dataStruct) {
  std::cout << "float: ";
  if (dataStruct.floatStr.empty() ||
      (!dataStruct.floatStr.empty() && dataStruct.type == NONE) ||
      std::isinf(dataStruct.doubleVal) || std::isnan(dataStruct.doubleVal)) {
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << dataStruct.floatVal << "f" << std::endl;
  } else
    std::cout << dataStruct.floatStr << std::endl;
}

void ScalarConverter::printDouble(const dataStruct& dataStruct) {
  std::cout << "double: ";
  if (dataStruct.floatStr.empty() ||
      (!dataStruct.floatStr.empty() && dataStruct.type == NONE)) {
    std::cout << std::fixed << std::showpoint << std::setprecision(1);
    std::cout << dataStruct.doubleVal << std::endl;
  } else {
    std::cout << dataStruct.doubleStr << std::endl;
  }
}

void ScalarConverter::convertActualData(dataStruct& dataStruct,
                                        const std::string& dataStr) {
  char* pEnd;
  const double dataDouble = std::strtod(dataStr.c_str(), &pEnd);

  dataStruct.dataStr = dataStr;

  if ((dataStr.length() == 1 && std::isalpha(*dataStr.c_str()))) {
    ScalarConverter::convertChar(dataStruct);
    dataStruct.type = CHAR;
  } else if (*pEnd == '\0' && !dataStr.empty() && dataDouble >= INT_MIN &&
             dataDouble <= INT_MAX) {
    ScalarConverter::convertInt(dataStruct);
    dataStruct.type = INT;
  } else if (dataStr.find('.') != std::string::npos && *pEnd == 'f' &&
             std::strlen(pEnd) == 1) {
    ScalarConverter::convertFloat(dataStruct);
    dataStruct.type = FLOAT;
  } else if (dataStr.find('.') != std::string::npos &&
             (!std::isinf(dataDouble) || !std::isnan(dataDouble))) {
    ScalarConverter::convertDouble(dataStruct);
    std::cerr << "what?" << std::endl;
    dataStruct.type = DOUBLE;
  } else {
    dataStruct.type = NONE;
  }
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
  } else if ((dataDouble >= std::numeric_limits<float>::min() &&
              dataDouble <= std::numeric_limits<float>::max()) ||
             dataStruct.type == NONE) {
    dataStruct.floatVal = static_cast<float>(dataDouble);
  } else {
    dataStruct.floatVal = static_cast<float>(dataDouble);
    dataStruct.floatStr = "impossible";
  }
}

void ScalarConverter::convertDouble(dataStruct& dataStruct) {
  const double dataDouble = std::strtod(dataStruct.dataStr.c_str(), NULL);

  if ((dataStruct.dataStr.length() == 1 &&
       std::isalpha(*dataStruct.dataStr.c_str()))) {
    dataStruct.doubleVal = static_cast<double>(*dataStruct.dataStr.c_str());
  } else if ((dataDouble >= std::numeric_limits<double>::min() &&
              dataDouble <= std::numeric_limits<double>::max()) ||
             dataStruct.type == NONE) {
    dataStruct.doubleVal = dataDouble;
  } else {
    dataStruct.doubleVal = dataDouble;
    dataStruct.doubleStr = "impossible";
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
      ScalarConverter::convertChar(dataStruct);
      ScalarConverter::convertInt(dataStruct);
      ScalarConverter::convertFloat(dataStruct);
      ScalarConverter::convertDouble(dataStruct);
      break;
  }
}

void ScalarConverter::convert(const std::string& dataStr) {
  if (!ScalarConverter::validCheckData(dataStr))
    throw ScalarConverter::ScalarValidError();

  dataStruct dataStruct;

  ScalarConverter::convertActualData(dataStruct, dataStr);
  ScalarConverter::convertOtherData(dataStruct);

  ScalarConverter::printChar(dataStruct);
  ScalarConverter::printInt(dataStruct);
  ScalarConverter::printFloat(dataStruct);
  ScalarConverter::printDouble(dataStruct);
}
