/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:20:21 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/24 15:03:29 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

std::string	cutString(const std::string& str)
{
	std::string	new_str = str;

	if (str.length() <= 10)
		return (str);
	new_str[9] = '.';
	new_str[10] = '\0';
	return (new_str);
}

void	executeCmd(std::string cmd, PhoneBook& phone_book)
{
	if (!cmd.compare("ADD"))
		return (phone_book.Add());
	if (!cmd.compare("SEARCH"))
		return (phone_book.Search());
	else
		std::cout << "Wrong Command!!\n";
	return ;
}
int main(void)
{
	PhoneBook phone_book;
	std::string cmd;

	while (true)
	{
		std::cout << "enter the command [ADD, SEARCH, EXIT]\n";
		std::getline(std::cin, cmd);
		if (std::cin.eof()) {return (1);}
		if (!cmd.compare("EXIT"))
			break;
		executeCmd(cmd, phone_book);
		if (std::cin.eof()) {return (1);}
	}
	return 0;
}
