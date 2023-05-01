/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:12:53 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/01 16:23:47 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

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
