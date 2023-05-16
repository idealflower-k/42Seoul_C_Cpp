/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:04:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 17:15:15 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	replaceFile(std::string file, std::string s1, std::string s2) {

	std::ifstream	infile(file);
	std::string		line;

	if (!infile.is_open())
		throw std::invalid_argument("open infile error");

	std::ofstream	outfile(file + ".replace");

	if (!outfile.is_open())
		throw std::invalid_argument("open oufile error");

	infile.seekg(0, std::ios::end); // 위치 지정자를 파일 끝으로 옮긴다.
	int	size = infile.tellg(); // 그 위치를 읽는다. (파일의 크기) 바이트 반환
	line.resize(size); // 그 크기의 문자열 할당
	infile.seekg(0, std::ios::beg);
	infile.read(&line[0], size);

	size_t pos = line.find(s1);

	while (pos != std::string::npos) {
		line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		pos = line.find(s1, pos + s2.length());
	}
	outfile << line;
}
