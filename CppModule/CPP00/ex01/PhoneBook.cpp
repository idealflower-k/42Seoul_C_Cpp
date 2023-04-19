/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/19 17:42:37 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

int	PhoneBook::Add()
{
	int	idx = (this->index % 9);
	Contact *contact = &(this->contact[idx]);

	std::cout << "enter first name\n";
	getline(std::cin, contact->first_name);	if(std::cin.eof()) return (1);
	std::cout << "enter last name\n";
	getline(std::cin, contact->last_name);	if(std::cin.eof()) return (1);
	std::cout << "enter nickname\n";
	getline(std::cin, contact->nickname);	if(std::cin.eof()) return (1);
	std::cout << "enter phone number\n";
	getline(std::cin, contact->phone_number);	if(std::cin.eof()) return (1);
	std::cout << "enter darkest secret\n";
	getline(std::cin, contact->darkest_secret);	if(std::cin.eof()) return (1);
	this->index = (idx + 1) % 9;
	return (0);
}

int	PhoneBook::Search()
{
	int idx = 0;
	std::string	input;
	Contact *contant;
	
	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << "|\n";
	while (idx <= this->index - 1)
	{
		std::cout << std::setw(10) << idx << '|';
		std::cout << std::setw(10) << this->contact[idx].first_name << '|';
		std::cout << std::setw(10) << this->contact[idx].last_name << '|';
		std::cout << std::setw(10) << this->contact[idx].nickname << "|\n";
		idx ++;
	}
	std::cout << "enter index number(0~9)\n";
	getline(std::cin, input);
	std::stringstream ss(input);
	ss >> idx; if(idx >= 9 || idx < 0) return (1);
	contant = &this->contact[idx];
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << '|';
	std::cout << std::setw(10) << "phonenumber" << '|';
	std::cout << std::setw(10) << "darkest_secret" << "|\n";
	std::cout << std::setw(10) << contact->first_name << '|';
	std::cout << std::setw(10) << contact->last_name << '|';
	std::cout << std::setw(10) << contact->nickname << '|';
	std::cout << std::setw(10) << contact->phone_number << '|';
	std::cout << std::setw(10) << contact->darkest_secret << "|\n";
	return (0);
}