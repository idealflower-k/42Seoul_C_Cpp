/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:04:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/02 16:31:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	replaceFile(std::string file, std::string s1, std::string s2) {
	std::ifstream	infile(file);
	std::string		line;

	if (!infile.is_open()) {std::cout << "file open error\n"; return (false);}
	while (infile) {
		std::getline(infile, line);
		// 문자열을 변환하는 함수 작성 필요
	// 	std::string s = "This is a sample string.";
	// 	std::string s1 = "sample";
	// 	std::string s2 = ".";

	// 	size_t pos = s.find(s1);
	// 	while (pos != std::string::npos) {
	// 	s = s.substr(0, pos) + s2 + s.substr(pos + s1.length());
	// 	pos = s.find(s1, pos + s2.length());
	// }
	// std::cout << s << std::endl;
	// return 0;
		std::cout << line << std::endl;
	}
	return (true);
}