/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:46:19 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/04 16:50:13 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int	main(int ac, char** av) {
	Harl	harl1;

	switch (ac) {
		case 0:
		case 1:
			std::cout << "enter the level" << std::endl;
			break ;
		case 2:
			harl1.complain(av[1]);
			break ;
		default:
			std:: cout << "enter the only one level" << std::endl;
	}
	return (0);
}