/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:53:30 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 17:34:45 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char** av) {

	try {
		if (ac != 4)
			throw std::invalid_argument("arguments error");

		replaceFile(av[1], av[2], av[3]);
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
