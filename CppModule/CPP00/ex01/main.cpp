/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:20:21 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/19 17:33:39 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int	executeCmd(std::string cmd, PhoneBook& phone_book)
{
	if (cmd == "ADD")
		return (phone_book.Add());
	if (cmd == "SEARCH")
		return (phone_book.Search());
	else
		return (1);
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
		if (executeCmd(cmd, phone_book))
			break ;
	}
	return (0);
}