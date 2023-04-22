/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/22 15:27:57 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	PhoneBook::Add() {
	int	idx = (this->next_index % 8);
	Contact *contact = &(this->contact[idx]);

	std::cout << "enter first name\n";
	getline(std::cin, contact->first_name);
	if(std::cin.eof()) {std::cin.clear();} return (1);
	std::cout << "enter last name\n";
	getline(std::cin, contact->last_name);
	if(std::cin.eof()) {std::cin.clear();}return (1);
	std::cout << "enter nickname\n";
	getline(std::cin, contact->nickname);
	if(std::cin.eof()) {std::cin.clear();}return (1);
	std::cout << "enter phone number\n";
	getline(std::cin, contact->phone_number);
	if(std::cin.eof()) {std::cin.clear();}return (1);
	std::cout << "enter darkest secret\n";
	getline(std::cin, contact->darkest_secret);
	if(std::cin.eof()) {std::cin.clear();}return (1);
	this->next_index = (idx + 1) % 8;
	if (this->use_index < 8)
		this->use_index++;
	return (0);
}

int	PhoneBook::Search() const {
	int idx = 0;
	std::string	input;
	
	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname" << "|\n";
	while (idx <= this->use_index - 1) {
		const Contact *contact = &(this->contact[idx]);

		std::cout << std::setw(10) << idx << '|';
		std::cout << std::setw(10) << cutString(contact->first_name) << '|';
		std::cout << std::setw(10) << cutString(contact->last_name) << '|';
		std::cout << std::setw(10) << cutString(contact->nickname) << "|\n";
		idx ++;
	}
	std::cout << "enter index number(0~7)\n";
	getline(std::cin, input);
	std::stringstream ss(input);
	ss >> idx; if(idx > 7 || idx < 0) return (1);
	this->Dispay(idx);
	return (0);
}

void	PhoneBook::Dispay(int idx) const {
	const Contact *contact = &this->contact[idx];

	std::cout << std::setw(15) << "first name :     " <<
		contact->first_name << std::endl;
	std::cout << std::setw(15) << "last name :      " <<
		contact->last_name << std::endl;
	std::cout << std::setw(15) << "nickname :       " <<
		contact->nickname << std::endl;
	std::cout << std::setw(15) << "phonenumber :    " <<
		contact->phone_number << std::endl;
	std::cout << std::setw(15) << "darkest_secret : " <<
		contact->darkest_secret << std::endl;
	return ;
}