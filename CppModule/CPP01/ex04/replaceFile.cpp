#include "main.h"

void	replaceFile(std::string file, std::string s1, std::string s2) {

	std::ifstream	infile(file);

	if (!infile.is_open())
		throw std::invalid_argument("open infile error");

	std::ofstream	outfile(file + ".replace");

	if (!outfile.is_open())
		throw std::invalid_argument("open oufile error");

	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string line = buffer.str();

	size_t pos = line.find(s1);

	while (pos != std::string::npos) {
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos = line.find(s1, pos + s2.length());
	}
	outfile << line;
}
