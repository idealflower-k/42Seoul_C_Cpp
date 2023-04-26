/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:36 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/26 14:43:55 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void		executeCmd(std::string cmd, PhoneBook& phone_book);
std::string	cutString(const std::string& str);
bool		isNumber(std::string& str);

#endif