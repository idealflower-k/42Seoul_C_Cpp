/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:10:20 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 17:37:34 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

int	main(void) {

	Harl	harl1;

	std::cout << "DEBUG: ";
	harl1.complain("DEBUG");

	std::cout << "INFO: ";
	harl1.complain("INFO");

	std::cout << "WARNING: ";
	harl1.complain("WARNING");

	std::cout << "ERROR: ";
	harl1.complain("ERROR");

	std::cout << "SOME: ";
	harl1.complain("SOME");
}
