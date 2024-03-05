#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void		executeCmd(std::string cmd, PhoneBook& phone_book);
std::string	cutString(const std::string& str);
bool		isNumber(std::string& str);

#endif
