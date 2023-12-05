#include "utils.hpp"

namespace utils {

std::string intToString(int value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}

std::string floatToString(float value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}

std::string doubleToString(double value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}

}  // namespace utils
