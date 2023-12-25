#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>

#define DATA_DELIMITER ","
#define INPUT_DELIMITER "|"
#define DATE_DELIMITER "-"
#define NO_DATA -1.0f
#define DATA_FORMAT "date,exchange_rate"
#define INPUT_FORMAT "date | value"
#define BAD_DATA_ERROR "bad data format in data file."
#define DATA_FILE_ERROR "data file could not open."
#define INPUT_FILE_ERROR "could not open file."
#define NEGATIVE_ERROR "not a positive number."
#define BAD_INPUT_ERROR "bad input."
#define TOO_LARGE_ERROR "too large number."
#define NO_DATA_ERROR "no data."
#define DATA_FILE "data.csv"

class BitcoinExchange {
 private:
  std::map<std::string, double> _data;
  std::string _inputFile;

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& origin);
  BitcoinExchange& operator=(const BitcoinExchange& origin);

  void setData();
  bool validFormat(std::string delimiter, std::string& input) const;
  bool validDate(std::string& date, size_t size);
  bool validYear(std::string& year) const;
  bool validMonth(std::string& month) const;
  bool validDay(std::string& year, std::string& month, std::string& day) const;
  bool isLeapYear(std::string& year) const;
  bool validRate(std::string& rate) const;
  bool validValue(std::string& value);
  double multivalue(std::string& date, double value);
  void printResult(std::string& date, double value, double result);
  void printError(std::string error, std::string date) const;

  void spaceTrim(std::string& str);
  void zeroTrim(std::string& str);
  int calculateDecimalPlaces(double value);
  std::string doubleToString(double value);

 public:
  BitcoinExchange(std::string inputFile);
  ~BitcoinExchange();

  void convert();
};

#endif
