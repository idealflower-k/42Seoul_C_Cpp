#include "main.h"

PhoneBook::PhoneBook() : next_index(0), use_index(0) {}

void PhoneBook::Add() {
	int idx = (this->next_index % 8);
	Contact* contact = &(this->contact[idx]);
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << "first_name: ";
	std::getline(std::cin, first_name);
	if (std::cin.eof() || first_name.empty())
		return;

	std::cout << "last_name: ";
	std::getline(std::cin, last_name);
	if (std::cin.eof() || last_name.empty())
		return;

	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	if (std::cin.eof() || nickname.empty())
		return;

	std::cout << "phone_number: ";
	std::getline(std::cin, phone_number);
	if (std::cin.eof() || phone_number.empty())
		return;

	std::cout << "darkest_secret: ";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof() || darkest_secret.empty())
		return;

	contact->first_name = first_name;
	contact->last_name = last_name;
	contact->nickname = nickname;
	contact->phone_number = phone_number;
	contact->darkest_secret = darkest_secret;

	this->next_index = (idx + 1) % 8;
	if (this->use_index < 8)
		this->use_index++;
	return;
}

void PhoneBook::Search() const {
	int idx = 0;
	std::string input;

	std::cout << std::setw(10) << "index" << '|';
	std::cout << std::setw(10) << "first name" << '|';
	std::cout << std::setw(10) << "last name" << '|';
	std::cout << std::setw(10) << "nickname"
			  << "|\n";

	while (idx <= this->use_index - 1) {
		const Contact* contact = &(this->contact[idx]);

		std::cout << std::setw(10) << idx << '|';
		std::cout << std::setw(10) << cutString(contact->first_name) << '|';
		std::cout << std::setw(10) << cutString(contact->last_name) << '|';
		std::cout << std::setw(10) << cutString(contact->nickname) << "|\n";
		idx++;
	}

	std::cout << "enter index number(0~7)\n";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
	std::stringstream ss(input);

	if (isNumber(input) && ss >> idx) {
		if (idx > 7 || idx < 0)
			return;
		this->Dispay(idx);
	}
	return;
}

void PhoneBook::Dispay(int idx) const {
	const Contact* contact = &this->contact[idx];

	std::cout << std::setw(15) << "first name :     " << contact->first_name << std::endl;

	std::cout << std::setw(15) << "last name :      " << contact->last_name << std::endl;

	std::cout << std::setw(15) << "nickname :       " << contact->nickname << std::endl;

	std::cout << std::setw(15) << "phonenumber :    " << contact->phone_number << std::endl;

	std::cout << std::setw(15) << "darkest_secret : " << contact->darkest_secret << std::endl;

	return;
}
