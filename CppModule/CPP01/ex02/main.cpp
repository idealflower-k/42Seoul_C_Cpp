#include <iostream>
#include <string>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& sttringREP = str;

	std::cout << "the string : " << str << std::endl;
	std::cout << "stringPTR  : " << stringPTR << std::endl;
	std::cout << "stringREF  : " << &sttringREP << std::endl;

	return (0);
}
