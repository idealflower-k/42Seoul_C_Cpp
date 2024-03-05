#include "main.h"

bool	isNumber(std::string& str) {
	for (std::string::const_iterator itr = str.begin(); itr != str.end(); ++itr)
		if (!isdigit(*itr)) return (false);
	return (true);
}

std::string	cutString(const std::string& str) {
	std::string	new_str = str;

	if (str.length() <= 10)
		return (str);
	new_str[9] = '.';
	new_str.erase(10, std::string::npos);
	return (new_str);
}

void	executeCmd(std::string cmd, PhoneBook& phone_book) {
	if (!cmd.compare("ADD"))
		return (phone_book.Add());
	if (!cmd.compare("SEARCH"))
		return (phone_book.Search());
	else
		std::cout << "Wrong Command!!\n";
	return ;
}

int main(void) {
	PhoneBook	phone_book;
	std::string	cmd;

	while (true) {
		std::cout << "Enter the command [ADD, SEARCH, EXIT]\n";
		std::getline(std::cin, cmd);
		if (std::cin.eof()) {std::cin.clear(); clearerr(stdin);}
		if (!cmd.compare("EXIT"))
			break;
		executeCmd(cmd, phone_book);
		if (std::cin.eof()) {
			std::cin.clear(); clearerr(stdin);
			std::cout << std::endl;
		}
	}
	return (0);
}
