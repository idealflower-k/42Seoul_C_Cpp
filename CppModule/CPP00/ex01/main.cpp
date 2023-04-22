/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:20:21 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/22 15:56:06 by sanghwal         ###   ########seoul.kr  */
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

int	executeCmd(std::string cmd, PhoneBook& phone_book)
{
	if (cmd == "ADD")
		return (phone_book.Add());
	if (cmd == "SEARCH")
		return (phone_book.Search());
	else
		std::cout << "Wrong Command!!\n";
	return (0);
}
int main(void)
{
    PhoneBook phone_book;
    std::string cmd;

    while (true)
    {
        std::cout << "enter the command [ADD, SEARCH, EXIT]\n";

        // getline()이 eof를 반환하면
        if (!std::getline(std::cin, cmd)) {
            // 클리어하고
            std::cin.clear();
            // 버퍼를 비우도록 합니다.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // continue로 다음 반복을 실행합니다.
            continue;
        }

        if (cmd == "EXIT")
            break;

        executeCmd(cmd, phone_book);
    }
    return 0;
}
