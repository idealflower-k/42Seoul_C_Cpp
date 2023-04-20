/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:36:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/20 19:45:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

static char*	chageToUpper(char* str)
{
	const int	LEN = std::strlen(str);

	for (int i = 0; i < LEN; i++) {
		str[i] = std::toupper((unsigned char)str[i]);
	}
	str = str;
	return (str);
}

int	main(int ac, char **av)
{
	char*	str;
	int		i = 1;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++) {
			str = chageToUpper(av[i]);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}
