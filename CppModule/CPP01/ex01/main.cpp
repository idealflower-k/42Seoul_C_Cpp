/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:00:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/15 21:10:58 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	try {
		Zombie* zombie_array = zombieHorde(-1, "arrayZombie");

		if (!zombie_array)
			throw std::invalid_argument("Failed to create zombie_array");

		for (int i = 0; i < 5; ++i)
			zombie_array[i].announce();

		delete[] zombie_array;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
