/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:12:29 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/18 20:39:56 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

#define INPUT_FILE_ERROR "could not open file."
#define NEGATIVE_ERROR "not a positive number."
#define BAD_INPUT_ERROR "bad input."
#define TOO_LARGE_ERROR "too large number."

class BitcoinExchange {
 private:
  std::map<std::string, double> _rates;
  std::string _inputFile;
  int _inputFd;
  BitcoinExchange();

  void printError(std::string error) const;

 public:
  BitcoinExchange(std::string inputFile);
  BitcoinExchange(const BitcoinExchange &origin);
  ~BitcoinExchange();

  BitcoinExchange &operator=(const BitcoinExchange &origin);

  void setRate(std::string date, double rate);
  void parseDataFile();
  bool vaildateDate(std::string date) const;
  bool vaildateRate(std::string rate) const;
  bool vaildateAmount(std::string amount) const;

  double getRate(std::string date) const;

  double convert(std::string date, double amount) const;
};

#endif
