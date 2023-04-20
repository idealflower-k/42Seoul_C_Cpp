/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:36 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/20 20:17:49 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <iomanip>
#include "phonebook.hpp"

int			executeCmd(std::string cmd, PhoneBook& phone_book);
std::string	cutString(const std::string& str);
#endif