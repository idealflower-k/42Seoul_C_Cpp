/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:42:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/16 16:26:54 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {
		if (N <= 0)
			throw std::invalid_argument("invalid_N");
		
		Zombie* zombie_array = NULL;
		try {
			zombie_array = new Zombie[N];
		} catch (const std::bad_alloc& e) {
			delete[] zombie_array;
			throw;
		}

		for (int i = 0; i < N; ++i) {
			zombie_array[i].setName(name);
		}

		return (zombie_array);
}
