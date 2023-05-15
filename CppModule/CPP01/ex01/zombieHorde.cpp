/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:42:14 by sanghwal          #+#    #+#             */
/*   Updated: 2023/05/15 20:52:28 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde(int N, std::string name) {

	if (N <= 0)
		return (NULL);
	Zombie* zombie_array = new Zombie[N];
	if (!zombie_array)
		return (NULL);

	for (int i = 0; i < N; ++i) {
		zombie_array[i].setName(name);
	}
	return (zombie_array);
}
