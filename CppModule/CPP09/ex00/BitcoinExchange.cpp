#include "BitcoinExchange.hpp"
// C++98 기준

BitcoinExchange::BitcoinExchange(std::string inputFile)
    : _inputFile(inputFile), _inputFd(0) {
  std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &origin)
    : _inputFile(origin._inputFile), _inputFd(origin._inputFd) {
  std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &origin) {
  std::cout << "BitcoinExchange assignation operator called" << std::endl;
  if (this == &origin) return (*this);
  this->_inputFile = origin._inputFile;
  this->_inputFd = origin._inputFd;
  return (*this);
}

void BitcoinExchange::printError(std::string error) const {
  std::cerr << "Error: " << error << std::endl;
}

void BitcoinExchange::parseDataFile() {
  std::ifstream ifs("data.csv");
  if (!ifs.is_open()) {
    this->printError(INPUT_FILE_ERROR);
    return;  // 종료
  }
  std::string line;
  while (std::getline(ifs, line)) {
    if (line.empty()) break;
    std::string date = line.substr(0, line.find_first_of(','));
    std::string rate = line.substr(line.find_first_of(',') + 1);
    if (!this->vaildateDate(date) || !this->vaildateRate(rate)) {
      std::cerr << BAD_INPUT_ERROR << std::endl;
      return;  // 종료
    }
    this->setRate(date, std::strtod(rate.c_str(), NULL));
  }
  ifs.close();
}

// vaildateDate: 날짜가 존재가능한 날짜인지 확인
bool BitcoinExchange::vaildateDate(std::string date) const {}

void BitcoinExchange::setRate(std::string date, double rate) {
  this->_rates[date] = rate;
}

double BitcoinExchange::getRate(std::string date) const {
  std::map<std::string, double>::const_iterator it = this->_rates.find(date);
  if (it == this->_rates.end()) return (0);
  return (it->second);
}

double BitcoinExchange::convert(std::string date, double amount) const {
  double rate = this->getRate(date);
  if (rate == 0) return (0);
  return (amount * rate);
}

BitcoinExchange::~BitcoinExchange() {
  std::cout << "BitcoinExchange destructor called" << std::endl;
}
