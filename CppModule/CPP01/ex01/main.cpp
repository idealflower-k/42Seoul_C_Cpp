/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:00:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 16:30:44 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {

		int		n;
		Zombie* zombie_array = NULL;
	try {
		n = 5;
		zombie_array = zombieHorde(n, "arrayZombie");

		for (int i = 0; i < n; ++i)
			zombie_array[i].announce();

		delete[] zombie_array;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
