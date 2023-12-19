#include "BitcoinExchange.hpp"

//   void setData();
//   bool vaildFormat(std::string delimiter, std::string input) const;
//   bool vaildDate(std::string date) const;
//   bool vaildYear(std::string year) const;
//   bool vaildMonth(std::string month) const;
//   bool vaildDay(std::string day) const;
//   bool vaildRate(std::string rate) const;
//   bool vaildValue(std::string value) const;
//   double multivalue(std::string date, double value) const;
//   void printResult(std::string date, double value, double result) const;

//  public:
//   BitcoinExchange(std::string inputFile);
//   ~BitcoinExchange();

//   void convert();

BitcoinExchange::BitcoinExchange(std::string inputFile)
    : _inputFile(inputFile) {
  this->setData();
}

void BitcoinExchange::setData() {
  std::ifstream ifs(DATA_FILE);
  std::string line;

  if (!ifs.is_open()) {
    throw std::runtime_error(DATA_FILE_ERROR);
  }
  std::getline(ifs, line);
  if ("date,exchange_rate" != line) {
    ifs.close();
    std::cerr << line << std::endl;
    throw std::runtime_error(BAD_DATA_ERROR);
  }
  while (std::getline(ifs, line)) {
    if (line.empty()) continue;

    size_t delPos = line.find(DATA_DELIMITER);
    if (delPos == std::string::npos) {
      ifs.close();
      throw std::runtime_error(BAD_DATA_ERROR);
    }

    std::string date = line.substr(0, line.find(DATA_DELIMITER));
    std::string value = line.substr(line.find(DATA_DELIMITER) + 1);
    if (!this->vaildFormat(DATA_DELIMITER, line) || !this->vaildDate(date) ||
        !this->vaildRate(value)) {
      ifs.close();
      throw std::runtime_error(BAD_DATA_ERROR);
    }
    this->_data[date] = std::stof(value);
  }
  ifs.close();
}

bool BitcoinExchange::vaildFormat(std::string delimiter,
                                  std::string& input) const {
  size_t delPos = input.find(delimiter);
  if (delPos == std::string::npos) return false;

  size_t lastDelPos = input.find_last_of(delimiter);
  if (delPos != lastDelPos) return false;

  return true;
}

bool BitcoinExchange::vaildDate(std::string& date) const {
  size_t delPos = date.find(DATE_DELIMITER);
  if (delPos == std::string::npos || date.size() != 10) return false;

  std::string year = date.substr(0, delPos);
  size_t lastDelPos = date.find_last_of(DATE_DELIMITER);
  if (delPos == lastDelPos) return false;
  std::string month = date.substr(delPos + 1, lastDelPos - delPos - 1);
  std::string day = date.substr(lastDelPos + 1);
  if (!this->vaildYear(year) || !this->vaildMonth(month) ||
      !this->vaildDay(year, month, day)) {
    return false;
  }
  return true;
}

bool BitcoinExchange::vaildYear(std::string& year) const {
  if (year.size() != 4) return false;
  for (size_t i = 0; i < year.size(); ++i) {
    if (!std::isdigit(year[i])) return false;
  }
  if (std::atoi(year.c_str()) < 1) return false;
  return true;
}

bool BitcoinExchange::vaildMonth(std::string& month) const {
  if (month.size() != 2) return false;
  for (size_t i = 0; i < month.size(); ++i) {
    if (!std::isdigit(month[i])) return false;
  }
  if (std::atoi(month.c_str()) < 1 || std::atoi(month.c_str()) > 12)
    return false;
  return true;
}

bool BitcoinExchange::isLeapYear(std::string& year) const {
  int intYear = std::atoi(year.c_str());

  return ((intYear % 4 == 0 && intYear % 100 != 0) || intYear % 400 == 0);
}

bool BitcoinExchange::vaildDay(std::string& year, std::string& month,
                               std::string& day) const {
  if (day.size() != 2) return false;
  for (size_t i = 0; i < day.size(); ++i) {
    if (!std::isdigit(day[i])) return false;
  }
  if (std::atoi(day.c_str()) < 1 || std::atoi(day.c_str()) > 31) return false;
  if (std::atoi(month.c_str()) == 2) {
    if (this->isLeapYear(year)) {
      if (std::atoi(day.c_str()) > 28) return false;
    } else {
      if (std::atoi(day.c_str()) > 29) return false;
    }
  } else if (std::atoi(month.c_str()) == 4 || std::atoi(month.c_str()) == 6 ||
             std::atoi(month.c_str()) == 9 || std::atoi(month.c_str()) == 11) {
    if (std::atoi(day.c_str()) > 30) return false;
  } else {
    if (std::atoi(day.c_str()) > 31) return false;
  }
  return true;
}

bool BitcoinExchange::vaildRate(std::string& value) const {
  if (value.empty()) return false;

  if (std::count(value.begin(), value.end(), '.') > 1) return false;

  for (size_t i = 0; i < value.size(); ++i) {
    if (!std::isdigit(value[i]) && value[i] != '.') return false;
  }

  if (std::atof(value.c_str()) < 0) return false;
  return true;
}

bool BitcoinExchange::vaildValue(std::string& value) const {
  if (value.empty()) return false;

  if (std::count(value.begin(), value.end(), '.') > 1) {
    this->printError(BAD_INPUT_ERROR, std::string());
    return false;
  }

  for (size_t i = 0; i < value.size(); ++i) {
    if (!std::isdigit(value[i]) && value[i] != '.') {
      this->printError(BAD_INPUT_ERROR, std::string());
      return false;
    }
  }

  float floatValue = std::atof(value.c_str());
  if (floatValue < 0) {
    this->printError(NEGATIVE_ERROR, std::string());
    return false;
  }
  if (floatValue > 1000) {
    this->printError(TOO_LARGE_ERROR, std::string());
    return false;
  }

  return true;
}

float BitcoinExchange::multivalue(std::string& date, float value) {
  std::map<std::string, float>::iterator dbIt = this->_data.lower_bound(date);

  if (dbIt == this->_data.begin() && dbIt->first.compare(date) != 0)
    return NO_DATA;

  if (dbIt != this->_data.begin() && dbIt->first.compare(date) != 0) --dbIt;

  return dbIt->second * value;
}

void BitcoinExchange::printResult(std::string& date, float value,
                                  float result) const {
  std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::printError(std::string error, std::string date) const {
  if (date.empty())
    std::cout << "Error: " << error << std::endl;
  else
    std::cout << "Error: " << error << " => " << date << std::endl;
}

void BitcoinExchange::convert() {
  std::ifstream ifs(this->_inputFile);
  std::string line;

  if (!ifs.is_open()) {
    throw std::runtime_error(INPUT_FILE_ERROR);
  }
  std::getline(ifs, line);
  if (line.compare(INPUT_FORMAT) != 0) {
    ifs.close();
    throw std::runtime_error(BAD_INPUT_ERROR);
  }
  while (std::getline(ifs, line)) {
    if (line.empty()) continue;

    if (this->vaildFormat(INPUT_DELIMITER, line) == false) {
      this->printError(BAD_INPUT_ERROR, line);
      continue;
    }

    std::string date = line.substr(0, line.find(INPUT_DELIMITER));
    std::string value = line.substr(line.find(INPUT_DELIMITER) + 1);
    this->spaceTrim(date);
    this->spaceTrim(value);

    if (!this->vaildDate(date)) {
      this->printError(BAD_INPUT_ERROR, date);
      continue;
    }
    if (!this->vaildValue(value)) continue;

    float floatValue = std::atof(value.c_str());
    float result = this->multivalue(date, floatValue);
    if (result == NO_DATA) {
      this->printError(NO_DATA_ERROR, date);
    } else {
      this->printResult(date, floatValue, result);
    }
  }
  ifs.close();
}

void BitcoinExchange::spaceTrim(std::string& str) {
  str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

BitcoinExchange::~BitcoinExchange() {}
