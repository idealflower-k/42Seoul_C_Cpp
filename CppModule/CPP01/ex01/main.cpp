/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:00:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/01 16:06:54 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int	main(void) {
	Zombie* zombie_array = zombieHorde(5, "arrayZombie");

	for (int i = 0; i < 5; ++i) {
		zombie_array[i].announce();
	}
	delete[] zombie_array;
	return (0);
}