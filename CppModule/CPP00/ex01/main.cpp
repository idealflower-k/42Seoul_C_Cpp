/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:20:21 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/20 20:15:03 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

std::string	cutString(const std::string& str)
{
	std::string	new_str = str;

	if (str.length() <= 10)
		return (str);
	new_str[9] = '.';
	new_str[10] = '\0';
	return (new_str);
}

int	executeCmd(std::string cmd, PhoneBook& phone_book)
{
	if (cmd == "ADD")
		return (phone_book.Add());
	if (cmd == "SEARCH")
		return (phone_book.Search());
	else
		std::cout << "Wrong Command\n";
	return (0);
}

int	main(void)
{
	PhoneBook phone_book;
	std::string	cmd;

	while (1)
	{
		std::cout << "enter the command ADD, SEARCH, EXIT\n";
		getline(std::cin, cmd); if(std::cin.eof()) return (0);
		if (cmd == "EXIT")
			break;
		executeCmd(cmd, phone_book);
	}
	return (0);
}
