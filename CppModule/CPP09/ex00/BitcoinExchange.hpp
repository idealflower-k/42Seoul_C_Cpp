#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
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
  std::map<std::string, float> _data;
  std::string _inputFile;

  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& origin);
  BitcoinExchange& operator=(const BitcoinExchange& origin);

  void setData();
  bool vaildFormat(std::string delimiter, std::string& input) const;
  bool vaildDate(std::string& date) const;
  bool vaildYear(std::string& year) const;
  bool vaildMonth(std::string& month) const;
  bool vaildDay(std::string& year, std::string& month, std::string& day) const;
  bool isLeapYear(std::string& year) const;
  bool vaildRate(std::string& rate) const;
  bool vaildValue(std::string& value) const;
  float multivalue(std::string& date, float value);
  void printResult(std::string& date, float value, float result) const;
  void printError(std::string error, std::string date) const;
  void spaceTrim(std::string& str);

 public:
  BitcoinExchange(std::string inputFile);
  ~BitcoinExchange();

  void convert();
};

#endif
