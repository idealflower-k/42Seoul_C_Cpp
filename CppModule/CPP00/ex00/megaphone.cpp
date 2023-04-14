/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:36:54 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/14 16:36:43 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static char*	chageToUpper(char* str)
{
	const int	LEN = strlen(str);

	for (int i = 0; i < LEN; i++) {
		str[i] = toupper(str[i]);
	}
	return (str);
}

int	main(int ac, char **av)
{
	char*	str = 0;
	int		i = 1;

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; i++) {
		str = chageToUpper(av[i]);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
