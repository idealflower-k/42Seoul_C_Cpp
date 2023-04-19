/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:32 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/19 17:32:08 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string darkest_secret;
		std::string	phone_number;
};

class PhoneBook
{
	private:
		Contact contact[8];
	public:
		int		index;
		PhoneBook(): index(0) {}
		int Add();
		int Search();
};

#endif